/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:56:19 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 17:09:14 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int		ft_wcs_char_len(wchar_t ch)
{
	if (ch < 128)
		return (1);
	else if (ch < 2048)
		return (2);
	else if (ch < 1 << 16)
		return (3);
	else if (ch < 1 << 21)
		return (4);
	return (1);
}

size_t	ft_wcsbytes(const wchar_t *s)
{
	int res;

	res = 0;
	while (*s)
	{
		res += ft_wcs_char_len(*s);
		s++;
	}
	return (res);
}

wchar_t	*ft_wcscut(wchar_t const *s, size_t len)
{
	unsigned int	i;
	wchar_t			*res;
	size_t			src_len;
	size_t			width;

	if (!s)
		return (NULL);
	width = 0;
	src_len = 0;
	i = 0;
	while (s[i] && width <= len)
	{
		width += ft_wcs_char_len(s[i]);
		if (width <= len)
			src_len++;
		i++;
	}
	res = ft_wcsnew(src_len);
	if (res)
	{
		i = -1;
		while (++i < src_len)
			res[i] = s[i];
	}
	return (res);
}

int		ft_wcsfixlen(wchar_t **str, wchar_t ch, int width, int side)
{
	int		len;
	int		bytes;
	wchar_t	*new;

	len = ft_wcslen(*str);
	bytes = ft_wcsbytes(*str);
	if (bytes >= width)
		return (bytes);
	new = ft_wcsnew(width - bytes + len);
	if (new)
	{
		if (side)
		{
			ft_wmemmove(new, *str, len);
			ft_wmemset(new + len, ch, width - bytes);
		}
		else
		{
			ft_wmemmove(new + (width - bytes), *str, len);
			ft_wmemset(new, ch, width - bytes);
		}
		free(*str);
		*str = new;
	}
	return (width);
}
