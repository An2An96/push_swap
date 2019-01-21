/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:20:02 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 14:11:07 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

void	parse_spec_body(char *body, va_list *ap, t_spec *spec)
{
	int res;

	spec->flags = 0;
	spec->size = SIZE_NONE;
	spec->accuracy = -1;
	spec->width = 0;
	while (*body)
	{
		res = 0;
		res = get_flags(*body, &(spec->flags));
		!res && (res = get_size(body, &(spec->size)));
		!res && (res = get_accuracy(body, ap, &(spec->accuracy)));
		!res && (res = get_width(body, ap, spec));
		body += res;
	}
}

int		get_width(char *body, va_list *ap, t_spec *spec)
{
	if (*body == '*')
	{
		spec->width = va_arg(*ap, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->flags = FLAG_MINUS;
		}
		return (1);
	}
	else
		spec->width = ft_atoi(body);
	return (get_number_width(spec->width));
}

int		get_flags(char ch, char *flags)
{
	return ((ch == '-' && (*flags |= FLAG_MINUS))
		|| (ch == '+' && (*flags |= FLAG_PLUS))
		|| (ch == ' ' && (*flags |= FLAG_SPACE))
		|| (ch == '#' && (*flags |= FLAG_OCTOP))
		|| (ch == '0' && (*flags |= FLAG_ZERO)));
}

int		get_accuracy(char *body, va_list *ap, int *accuracy)
{
	if (*body == '.')
	{
		if (*(body + 1) == '*')
		{
			*accuracy = va_arg(*ap, int);
			if (*accuracy < 0)
				*accuracy = -1;
			return (1 + 1);
		}
		else if (ft_isdigit(*(body + 1)))
		{
			*accuracy = ft_atoi(body + 1);
			return (get_number_width(*accuracy) + 1);
		}
		else
		{
			*accuracy = 0;
			return (1);
		}
	}
	return (0);
}

char	get_size(char *body, char *size)
{
	char new_size;

	new_size = 0;
	if (*body == 'L')
		new_size = SIZE_L;
	else if (*body == 'z')
		new_size = SIZE_z;
	else if (*body == 'j')
		new_size = SIZE_j;
	else if (*body == 'l' && *(body + 1) == 'l')
		new_size = SIZE_ll;
	else if (*body == 'l')
		new_size = SIZE_l;
	else if (*body == 'h' && *(body + 1) == 'h')
		new_size = SIZE_hh;
	else if (*body == 'h')
		new_size = SIZE_h;
	if (new_size)
	{
		*size = *size < new_size ? new_size : *size;
		return (new_size == SIZE_hh || new_size == SIZE_ll) ? 2 : 1;
	}
	return (0);
}
