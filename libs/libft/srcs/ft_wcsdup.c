/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:24:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 19:25:14 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsdup(const wchar_t *src)
{
	int		i;
	wchar_t	*dest;

	dest = NULL;
	if (src)
	{
		dest = (wchar_t*)malloc((ft_wcslen(src) + 1) * sizeof(wchar_t));
		if (dest)
		{
			i = 0;
			while (src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (dest);
}
