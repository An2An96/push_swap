/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:55:44 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*ft_iina(uintmax_t value, char size, int len)
{
	if (size == SIZE_L)
		return (pf_uitoa_base((uint64_t)value, 16, len));
	else if (size == SIZE_l)
		return (pf_uitoa_base((unsigned long)value, 16, len));
	else if (size == SIZE_ll)
		return (pf_uitoa_base((unsigned long long)value, 16, len));
	else if (size == SIZE_hh)
		return (pf_uitoa_base((unsigned char)value, 16, len));
	else if (size == SIZE_h)
		return (pf_uitoa_base((unsigned short int)value, 16, len));
	else if (size == SIZE_j)
		return (pf_uitoa_base(value, 16, len));
	else if (size == SIZE_z)
		return (pf_uitoa_base((size_t)value, 16, len));
	return (pf_uitoa_base((unsigned int)value, 16, len));
}

static int	checkacc(va_list *ap, t_spec *spec, char **res, int *ox)
{
	char		*buf;
	uintmax_t	value;

	*ox = 0;
	value = va_arg(*ap, uintmax_t);
	if (spec->accuracy == -1 || spec->accuracy > 0)
	{
		buf = *res;
		if (IS_FLAG(FLAG_OCTOP) && value)
			*ox = 2;
		if (IS_FLAG(FLAG_ZERO) && !(IS_FLAG(FLAG_MINUS)))
			spec->accuracy = (spec->accuracy == -1
				? (spec->width - *ox) : spec->accuracy);
		else
			spec->accuracy = (spec->accuracy > 0 ? spec->accuracy : 0);
		if ((*res = ft_iina(value, spec->size, spec->accuracy)) == NULL)
			return (-1);
		free(buf);
		return (1);
	}
	else
		return (0);
}

static void	ft_getstr(char **res, va_list *ap, t_spec *spec)
{
	int		ox;
	char	*buf;

	if (checkacc(ap, spec, res, &ox) == -1)
		return ;
	if (spec->width > 1 && spec->width - (ft_strlen(*res) + ox) > 0)
	{
		if (ox != 0)
		{
			buf = *res;
			*res = ft_strjoin("0x", *res);
			free(buf);
			ox = 0;
		}
		ft_str_fixlen(res, ' ', spec->width - ox, IS_FLAG(FLAG_MINUS));
	}
	if (ox != 0)
	{
		buf = *res;
		*res = ft_strjoin("0x", *res);
		free(buf);
	}
}

int			print_hex(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		tmp;

	res = ft_strdup("");
	ft_getstr(&res, ap, spec);
	if (res == NULL)
		return (0);
	tmp = ft_strlen(res);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int			print_hex_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		tmp;

	res = ft_strdup("");
	ft_getstr(&res, ap, spec);
	if (res == NULL)
		return (0);
	ft_strupper(res);
	tmp = ft_strlen(res);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}
