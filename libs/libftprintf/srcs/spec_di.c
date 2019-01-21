/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:56:24 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static intmax_t	get_value(va_list *ap, t_spec *spec)
{
	if (spec->size == SIZE_l)
		return (va_arg(*ap, long));
	else if (spec->size == SIZE_ll)
		return (va_arg(*ap, long long));
	else if (spec->size == SIZE_j)
		return (va_arg(*ap, intmax_t));
	else if (spec->size == SIZE_z)
		return (va_arg(*ap, size_t));
	else
		return (va_arg(*ap, int));
}

static char		*get_string_value(intmax_t value, t_spec *spec)
{
	if (value || spec->accuracy)
	{
		if (spec->size == SIZE_h)
			return (ft_extend_itoa(
				(short int)value, spec->accuracy, IS_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_hh)
			return (ft_extend_itoa(
				(signed char)value, spec->accuracy, IS_FLAG(FLAG_PLUS)));
		else
			return (ft_extend_itoa(
				value, spec->accuracy, IS_FLAG(FLAG_PLUS)));
	}
	return (ft_strnew(0));
}

int				print_number(va_list *ap, t_spec *spec, int *len)
{
	char		*res;
	int			tmp;
	intmax_t	val;

	val = get_value(ap, spec);
	if (spec->accuracy == -1 && IS_FLAG(FLAG_ZERO) && !IS_FLAG(FLAG_MINUS))
	{
		spec->width -= (val < 0 || IS_FLAG(FLAG_PLUS));
		spec->accuracy = spec->accuracy > spec->width ? spec->accuracy
			: spec->width - (IS_FLAG(FLAG_SPACE) && !IS_FLAG(FLAG_PLUS));
		spec->width = 0;
	}
	if ((res = get_string_value(val, spec)) == 0)
		return (0);
	tmp = ft_str_fixlen(&res, ' ', spec->width, IS_FLAG(FLAG_MINUS));
	if (!spec->width && IS_FLAG(FLAG_SPACE) && !IS_FLAG(FLAG_PLUS) && val >= 0)
	{
		ft_putchar(' ');
		write(1, res, tmp++);
	}
	else
		write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int				print_long_number(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_number(ap, spec, len));
}
