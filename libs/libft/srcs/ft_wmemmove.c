/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:11:55 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 19:12:13 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_wmemmove(wchar_t *dst, const wchar_t *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	while (len-- > 0)
		dst[len] = src[len];
	return (dst);
}
