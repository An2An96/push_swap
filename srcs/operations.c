/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:57:51 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 13:11:15 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_push(t_list **stack_head_src, t_list **stack_head_dst)
{
	t_list *src_second;

	if (*stack_head_src)
	{
		src_second = (*stack_head_src)->next;
		(*stack_head_src)->next = (*stack_head_dst);
		*stack_head_dst = *stack_head_src;
		*stack_head_src = src_second;
	}
}

void	ps_swap(t_list **stack_head)
{
	t_list *second;

	second = (*stack_head)->next;
	if (second)
	{
		(*stack_head)->next = second->next;
		second->next = *stack_head;
		*stack_head = second;
	}
}

void	ps_rotate(t_list **stack_head)
{
	t_list *first_el;
	t_list *cur;

	if (*stack_head && (*stack_head)->next)
	{
		first_el = *stack_head;
		*stack_head = first_el->next;
		cur = *stack_head;
		while (cur->next)
			cur = cur->next;
		cur->next = first_el;
		first_el->next = NULL;
	}
}

void	ps_reverse_rotate(t_list **stack_head)
{
	t_list *cur;

	if (*stack_head && (*stack_head)->next)
	{
		cur = *stack_head;
		while (cur->next && (cur->next)->next)
			cur = cur->next;
		(cur->next)->next = (*stack_head);
		*stack_head = cur->next;
		cur->next = NULL;
	}
}
