/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:19:52 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:27:35 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long long n, int base)
{
	long long	unsig_n;
	int			discharges;
	char		*res;
	char		sign;

	sign = (n < 0);
	discharges = sign + 1;
	unsig_n = ABS(n);
	while ((n /= base))
		discharges++;
	res = ft_strnew(discharges);
	if (res)
	{
		while (discharges > sign)
		{
			n = unsig_n % base;
			res[--discharges] = n + ((n < 10) ? '0' : 'A' - 10);
			unsig_n /= base;
		}
		if (sign)
			res[--discharges] = '-';
	}
	return (res);
}
