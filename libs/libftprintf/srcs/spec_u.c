/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:55:44 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*get_value(va_list *ap, t_spec *spec)
{
	char		*res;
	uintmax_t	value;

	value = va_arg(*ap, uintmax_t);
	if (value || spec->accuracy != 0)
	{
		if (spec->size == SIZE_l)
			res = ft_uitoa_base((unsigned long)value, 10);
		else if (spec->size == SIZE_ll)
			res = ft_uitoa_base((unsigned long long)value, 10);
		else if (spec->size == SIZE_h)
			res = ft_uitoa_base((unsigned short int)value, 10);
		else if (spec->size == SIZE_hh)
			res = ft_uitoa_base((unsigned char)value, 10);
		else if (spec->size == SIZE_j)
			res = ft_uitoa_base(value, 10);
		else if (spec->size == SIZE_z)
			res = ft_uitoa_base((size_t)value, 10);
		else
			res = ft_uitoa_base((unsigned int)value, 10);
		ft_str_fixlen(&res, '0', spec->accuracy, 0);
	}
	else
		res = ft_strnew(0);
	return (res);
}

int			print_unsigned(va_list *ap, t_spec *spec, int *len)
{
	int		tmp;
	char	*res;

	res = get_value(ap, spec);
	if (!res)
		return (0);
	tmp = ft_strlen(res);
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

int			print_long_unsigned(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_unsigned(ap, spec, len));
}
