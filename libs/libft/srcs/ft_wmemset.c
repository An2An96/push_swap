/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:11:02 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 19:11:17 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_wmemset(wchar_t *str, int c, size_t n)
{
	while (n > 0)
	{
		str[n - 1] = c;
		n--;
	}
	return (str);
}
