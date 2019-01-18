/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:52:43 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/27 20:08:56 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(unsigned long long num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num /= base;
	}
	return (i);
}

char		*ft_uitoa_base(unsigned long long num, int base)
{
	char			*res;
	unsigned int	digs;
	int				i;

	digs = ft_digits(num, base);
	if ((res = (char *)malloc(sizeof(char) * (digs + 1))) == NULL)
		return (NULL);
	i = digs;
	while (--i >= 0)
	{
		if (num % base < 10)
			res[i] = num % base + '0';
		else
			res[i] = num % base + 87;
		num /= base;
	}
	res[digs] = '\0';
	return (res);
}
