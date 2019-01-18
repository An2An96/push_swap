/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2019/01/17 12:22:31 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dtoa(long double num, int acc)
{
	ssize_t		nbr;
	char		*fraction;
	char		*buf;
	char		*res;
	ssize_t		eps;

	eps = (ssize_t)ft_pow(10, acc);
	nbr = (ssize_t)(num < 0 ? -1 : 1) * ((ABS(num) + 0.5 / eps) * eps);
	if (acc == 0)
		return (ft_stoa(nbr / eps));
	fraction = ft_stoa(ABS(nbr) % eps);
	if (ft_strlen(fraction) < (size_t)acc)
		ft_str_fixlen(&fraction, '0', acc, 0);
	buf = ft_strjoin(ft_stoa(nbr / eps), ".");
	res = ft_strjoin(buf, fraction);
	free(buf);
	return (res);
}
