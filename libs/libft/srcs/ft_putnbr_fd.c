/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:04:19 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 16:43:13 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long n, int fd)
{
	unsigned long long us_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		us_n = -n;
	}
	else
		us_n = n;
	if (us_n / 10)
		ft_putnbr_fd((long long)(us_n / 10), fd);
	ft_putchar_fd((us_n % 10) + '0', fd);
}
