/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:49:33 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:08:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stack_new(int size)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack)
	{
		stack->head = (int*)malloc(size * sizeof(int));
		stack->len = 0;
		stack->size = size;
	}
	return (stack);
}

void	extend_stack(t_stack *stack, int add_size)
{
	int *tmp;

	if (stack)
	{
		stack->size += add_size;
		tmp = (int*)malloc(stack->size * sizeof(int));
		if (stack->head)
		{
			ft_memmove(tmp, stack->head, stack->len * 4);
			free(stack->head);
		}
		stack->head = tmp;
	}
}

void	stack_push(t_stack *stack, int value)
{
	int i;

	if (stack->size > stack->len)
	{
		i = stack->len;
		while (i > 0)
		{
			stack->head[i] = stack->head[i - 1];
			i--;
		}
		stack->head[i] = value;
		stack->len++;
	}
}

int		stack_pop(t_stack *stack)
{
	int i;
	int value;

	value = 0;
	if (stack->len)
	{
		value = stack->head[0];
		i = 0;
		while (i < (stack->len - 1))
		{
			stack->head[i] = stack->head[i + 1];
			i++;
		}
		stack->head[i] = 0;
		stack->len--;
	}
	return (value);
}

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
