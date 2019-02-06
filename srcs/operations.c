/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:57:51 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:17:53 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_push(t_stack *stack_head_src, t_stack *stack_head_dst)
{
	stack_push(stack_head_dst, stack_pop(stack_head_src));
}

void	ps_swap(t_stack *stack, t_stack *stack_unused)
{
	int tmp;

	(void)stack_unused;
	if (stack->len > 1)
	{
		tmp = stack->head[1];
		stack->head[1] = stack->head[0];
		stack->head[0] = tmp;
	}
}

void	ps_rotate(t_stack *stack, t_stack *stack_unused)
{
	int tmp;
	int i;

	(void)stack_unused;
	if (stack->len > 1)
	{
		tmp = stack->head[0];
		i = 0;
		while (i < (stack->len - 1))
		{
			stack->head[i] = stack->head[i + 1];
			i++;
		}
		stack->head[i] = tmp;
	}
}

void	ps_reverse_rotate(t_stack *stack, t_stack *stack_unused)
{
	int tmp;
	int i;

	(void)stack_unused;
	if (stack->len > 1)
	{
		tmp = stack->head[stack->len - 1];
		i = stack->len - 1;
		while (i)
		{
			stack->head[i] = stack->head[i - 1];
			i--;
		}
		stack->head[0] = tmp;
	}
}
