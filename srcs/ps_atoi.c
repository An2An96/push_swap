/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:15:28 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:02:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ps_atoi(const char *str)
{
	char	negative;
	long	result;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = 1 - (2 * (str[i] == '-'));
		i++;
	}
	else
		negative = 1;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if (result < 0)
			return (-((negative + 1) / 2));
		i++;
	}
	return ((long)result * negative);
}
