/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 15:50:27 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

char	*ft_strcut(char const *s, size_t len)
{
	unsigned int	i;
	char			*res;
	size_t			src_len;

	res = NULL;
	if (s)
	{
		src_len = ft_strlen(s);
		len = len > src_len ? src_len : len;
		res = ft_strnew(len);
		if (res)
		{
			i = 0;
			while (i < len)
			{
				res[i] = s[i];
				i++;
			}
		}
	}
	return (res);
}

int		print_unicode_string(wchar_t *value, t_spec *spec, int *len)
{
	int		tmp;
	wchar_t	*res;

	if (!value)
		value = ft_wcsjoin(value, L"(null)");
	else
		value = ft_wcsdup(value);
	if (spec->accuracy >= 0)
		res = ft_wcscut(value, spec->accuracy);
	else
		res = value;
	if (!res)
		return (0);
	if (IS_FLAG(FLAG_MINUS))
		tmp = ft_wcsfixlen(&res, ' ', spec->width, 1);
	else
		tmp = ft_wcsfixlen(&res,
			IS_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, 0);
	*len += ft_wcsbytes(res);
	ft_putwstr(res);
	free(res);
	return (1);
}

int		print_byte_string(char *value, t_spec *spec, int *len)
{
	int		tmp;
	char	*res;

	if (!value)
		value = ft_strjoin(value, "(null)");
	else
		value = ft_strdup(value);
	if (spec->accuracy >= 0)
		res = ft_strcut(value, spec->accuracy);
	else
		res = value;
	if (!res)
		return (0);
	if (IS_FLAG(FLAG_MINUS))
		tmp = ft_str_fixlen(&res, ' ', spec->width, 1);
	else
		tmp = ft_str_fixlen(&res,
			IS_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, 0);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int		print_string(va_list *ap, t_spec *spec, int *len)
{
	if (spec->size == SIZE_l)
		return (print_unicode_string(va_arg(*ap, wchar_t*), spec, len));
	else
		return (print_byte_string(va_arg(*ap, char*), spec, len));
}

int		print_long_string(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_string(ap, spec, len));
}
