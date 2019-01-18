/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:48:32 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:44:11 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c < 128)
		ft_putchar(c);
	else if (c < 2048)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 63) | 0x80);
	}
	else if (c < 1 << 16)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar((c >> 6 & 63) | 0x80);
		ft_putchar((c & 63) | 0x80);
	}
	else if (c < 1 << 21)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar((c >> 12 & 63) | 0x80);
		ft_putchar((c >> 6 & 63) | 0x80);
		ft_putchar((c & 63) | 0x80);
	}
}
