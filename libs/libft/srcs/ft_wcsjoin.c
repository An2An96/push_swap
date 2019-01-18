/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:21:08 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 19:21:20 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*res;
	size_t	s1_len;

	res = NULL;
	s1_len = ft_wcslen(s1);
	res = ft_wcsnew(s1_len + ft_wcslen(s2));
	if (res)
	{
		ft_wcscpy(res, s1);
		ft_wcscpy(res + s1_len, s2);
	}
	return (res);
}
