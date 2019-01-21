/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:37 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 16:37:00 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int		is_spec_body_char(char ch)
{
	return (ft_isdigit(ch) || ch == ' ' || ch == '-' || ch == '+' || ch == '#'
		|| ch == '.' || ch == '*' || ch == 'l' || ch == 'h' || ch == 'L'
		|| ch == 'z' || ch == 'j');
}

int		get_number_width(int number)
{
	int discharges;

	discharges = number < 0;
	if (number == 0)
		return (discharges + 1);
	while (number / 10 || number % 10)
	{
		number /= 10;
		discharges++;
	}
	return (discharges);
}
