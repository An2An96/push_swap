/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:17:21 by anorjen           #+#    #+#             */
/*   Updated: 2019/01/16 15:57:41 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

char	*ft_numtohex(long double num, int acc)
{
	char		*res;
	int			i;
	int			dig;
	int			ast;

	ast = acc;
	acc = (acc == -1 ? 13 : acc);
	num = num - 1.0;
	res = (char *)malloc(sizeof(char) * (acc + 3));
	i = -1;
	res[++i] = '1';
	while (++i < acc + 2 && !((dig = (int)(num * 16)) == 0 && ast == -1))
	{
		if (i == 1)
			res[i++] = '.';
		res[i] = (dig > 9 ? dig + 87 : dig + '0');
		num = num * 16 - dig;
	}
	res[i] = '\0';
	i--;
	if ((dig = (int)(num * 16)) >= 8)
		res[i] = (res[i] >= '9' && res[i] < 'a' ? 'a' : res[i] + 1);
	return (res);
}
