/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:28:02 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:55:44 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*get_value(va_list *ap, t_spec *spec)
{
	char		*res;
	uintmax_t	value;

	value = va_arg(*ap, uintmax_t);
	if (value || spec->accuracy)
	{
		if (spec->size == SIZE_l)
			res = ft_uitoa_base((unsigned long)value, 8);
		else if (spec->size == SIZE_ll)
			res = ft_uitoa_base((unsigned long long)value, 8);
		else if (spec->size == SIZE_h)
			res = ft_uitoa_base((unsigned short int)value, 8);
		else if (spec->size == SIZE_hh)
			res = ft_uitoa_base((unsigned char)value, 8);
		else if (spec->size == SIZE_j)
			res = ft_uitoa_base(value, 8);
		else if (spec->size == SIZE_z)
			res = ft_uitoa_base((size_t)value, 8);
		else
			res = ft_uitoa_base((unsigned int)value, 8);
		ft_str_fixlen(&res, '0', spec->accuracy, 0);
	}
	else
		res = ft_strnew(0);
	return (res);
}

int			print_octal(va_list *ap, t_spec *spec, int *len)
{
	int		tmp;
	char	*res;
	char	*value;

	res = get_value(ap, spec);
	if (!res)
		return (0);
	tmp = ft_strlen(res);
	if (res[0] != '0' && spec->flags & FLAG_OCTOP)
	{
		value = ft_strjoin("0", res);
		free(res);
		res = value;
	}
	if (spec->flags & FLAG_MINUS)
		tmp = ft_str_fixlen(&res, ' ',
			spec->width, spec->flags & FLAG_MINUS);
	else if (spec->accuracy == -1 && IS_FLAG(FLAG_ZERO))
		tmp = ft_str_fixlen(&res, '0', spec->width, 0);
	else
		tmp = ft_str_fixlen(&res, ' ', spec->width, 0);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int			print_long_octal(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_octal(ap, spec, len));
}
