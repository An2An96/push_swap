/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 17:07:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

int			find_specifier(const char ch)
{
	int i;

	i = 0;
	while (g_dispatcher[i].type_specifier)
	{
		if (ch == g_dispatcher[i].type_specifier)
			return (i);
		i++;
	}
	return (-1);
}

static int	specifier_handler(int spec_idx, char **body, va_list *ap, int *len)
{
	t_spec			spec;

	parse_spec_body(*body, ap, &spec);
	ft_strdel(body);
	if (g_dispatcher[spec_idx].func(ap, &spec, len))
		return (1);
	else
	{
		*len = -1;
		return (0);
	}
}

static int	spec_body_handler(
	const char *format, char **start, va_list *ap, int *len)
{
	t_spec	spec;
	int		spec_idx;
	int		res;

	res = 1;
	if (!is_spec_body_char(*format))
	{
		*start = ft_strsub(*start, 1, format - *start - 1);
		if ((spec_idx = find_specifier(*format)) >= 0)
			res = specifier_handler(spec_idx, start, ap, len);
		else
		{
			parse_spec_body(*start, ap, &spec);
			ft_strdel(start);
			if ((res = print_byte_char(*format, &spec, len)) == 0)
				*len = -1;
			*start = NULL;
		}
	}
	return (res);
}

static void	format_handler(const char *format, va_list *ap, int *len)
{
	char	*start;

	start = NULL;
	while (*format)
	{
		if (start)
		{
			if (spec_body_handler(format, &start, ap, len) == 0)
				return ;
		}
		else if (*format == '%')
			start = (char*)format;
		else
		{
			ft_putchar(*format);
			(*len)++;
		}
		format++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	format_handler(format, &ap, &len);
	va_end(ap);
	return (len);
}
