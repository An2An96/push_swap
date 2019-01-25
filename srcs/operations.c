/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:57:51 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/23 16:17:34 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stack.h"

void	ps_push(t_stack *stack_head_src, t_stack *stack_head_dst)
{
	// t_stack *src_second;

	stack_push(stack_head_dst, stack_pop(stack_head_src));

	// if (*stack_head_src)
	// {
	// 	src_second = (*stack_head_src)->next;
	// 	(*stack_head_src)->next = (*stack_head_dst);
	// 	*stack_head_dst = *stack_head_src;
	// 	*stack_head_src = src_second;
	// }
}

void	ps_swap(t_stack *stack, t_stack *stack_unused)
{
	// t_list *second;
	int tmp;

	(void)stack_unused;
	if (stack->len > 1)
	{
		tmp = stack->head[1];
		stack->head[1] = stack->head[0];
		stack->head[0] = tmp;
	}

	// second = (*stack_head)->next;
	// if (second)
	// {
	// 	(*stack_head)->next = second->next;
	// 	second->next = *stack_head;
	// 	*stack_head = second;
	// }
}

void	ps_rotate(t_stack *stack, t_stack *stack_unused)
{
	// t_list *first_el;
	// t_list *cur;
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

	// if (*stack_head && (*stack_head)->next)
	// {
	// 	first_el = *stack_head;
	// 	*stack_head = first_el->next;
	// 	cur = *stack_head;
	// 	while (cur->next)
	// 		cur = cur->next;
	// 	cur->next = first_el;
	// 	first_el->next = NULL;
	// }
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

	// t_list *cur;

	// (void)stack_unused;
	// if (*stack_head && (*stack_head)->next)
	// {
	// 	cur = *stack_head;
	// 	while (cur->next && (cur->next)->next)
	// 		cur = cur->next;
	// 	(cur->next)->next = (*stack_head);
	// 	*stack_head = cur->next;
	// 	cur->next = NULL;
	// }
}
