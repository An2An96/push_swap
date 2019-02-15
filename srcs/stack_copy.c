/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:08:07 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:24:36 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_copy(t_stack *src)
{
	t_stack	*dst;

	dst = (t_stack*)malloc(sizeof(t_stack));
	dst->size = src->size;
	dst->len = src->len;
	dst->head = (int*)malloc(src->size * sizeof(int));
	if (src->len)
		ft_memmove(dst->head, src->head, src->len * 4);
	else
		dst->head = NULL;
	return (dst);
}
