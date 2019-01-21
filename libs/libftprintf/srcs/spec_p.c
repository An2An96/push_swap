/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 14:23:18 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*get_value(void *value, t_spec *spec)
{
	char	*res;

	if ((size_t)value)
		res = ft_itoa_base((size_t)value, 16);
	else
		res = ft_strdup(spec->accuracy ? "0" : "");
	return (res);
}

int			print_pointer(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	void	*value;
	int		tmp;

	if (!(res = get_value(va_arg(*ap, void*), spec)))
		return (0);
	if (spec->accuracy == -1 && IS_FLAG(FLAG_ZERO) && !IS_FLAG(FLAG_MINUS))
	{
		spec->accuracy = spec->accuracy > spec->width ? spec->accuracy
			: spec->width - (IS_FLAG(FLAG_SPACE)) - 2;
		spec->width = 0;
	}
	ft_str_fixlen(&res, '0', spec->accuracy, 0);
	value = ft_strjoin("0x", ft_strlower(res));
	free(res);
	res = value;
	ft_str_fixlen(&res, ' ', spec->width, IS_FLAG(FLAG_MINUS));
	tmp = ft_strlen(res);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}
