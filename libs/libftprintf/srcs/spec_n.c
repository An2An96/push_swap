/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:15:44 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 13:52:20 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	write_len(va_list *ap, t_spec *spec, int *len)
{
	size_t *ptr;

	(void)spec;
	ptr = va_arg(*ap, size_t*);
	*ptr = *len;
	return (1);
}
