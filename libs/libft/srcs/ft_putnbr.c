/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 16:43:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n)
{
	unsigned long long us_n;

	if (n < 0)
	{
		ft_putchar('-');
		us_n = -n;
	}
	else
		us_n = n;
	if (us_n / 10)
		ft_putnbr((long long)(us_n / 10));
	ft_putchar((us_n % 10) + '0');
}
