/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 14:58:10 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_unicode_char(wchar_t ch, t_spec *spec, int *len)
{
	int		i;
	char	ch_width;

	i = 0;
	ch_width = ft_wcs_char_len(ch);
	spec->width -= ch_width;
	if (IS_FLAG(FLAG_MINUS))
	{
		ft_putwchar(ch);
		while (i++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < spec->width)
			ft_putchar(IS_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putwchar(ch);
	}
	*len += (spec->width > 0 ? spec->width : 0) + ch_width;
	return (1);
}

int	print_byte_char(char ch, t_spec *spec, int *len)
{
	int		i;

	i = 0;
	if (IS_FLAG(FLAG_MINUS))
	{
		ft_putwchar(ch);
		while (++i < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec->width)
			ft_putchar(IS_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putwchar(ch);
	}
	*len += spec->width > 0 ? spec->width : 1;
	return (1);
}

int	print_char(va_list *ap, t_spec *spec, int *len)
{
	if (spec->size == SIZE_l)
		return (print_unicode_char(va_arg(*ap, wchar_t), spec, len));
	else
		return (print_byte_char(va_arg(*ap, int), spec, len));
}

int	print_long_char(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_char(ap, spec, len));
}
