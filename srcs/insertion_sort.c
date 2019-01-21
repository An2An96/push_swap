/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:46:14 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 14:17:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_in_stack(t_list *stack_head, int stack_len, int sorted)
{
	int		min;
	int		min_idx;
	int		idx;
	t_list	*cur;

	if (!stack_head)
		return (-1);
	min = *((int*)stack_head->content);
	min_idx = 0;
	cur = stack_head->next;
	idx = 1;
	while (cur && idx < (stack_len - sorted))
	{
		if (*((int*)cur->content) < min)
		{
			min = *((int*)cur->content);
			min_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (min_idx);
}

int			insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int i;
	int min_idx;
	int sorted;
	int stack_len;
	int cmd_count;

	stack_len = ft_lstlen(*stack_a);
	sorted = 0;
	cmd_count = 0;
	while (sorted < stack_len)
	{
		if ((min_idx = find_min_in_stack(*stack_a, stack_len, sorted)) > 0)
		{
			i = 0;
			while (i < min_idx - 1)
			{
				ps_push(stack_a, stack_b); cmd_count++;
				// printf("pb\n");
				i++;
			}
			ps_swap(stack_a); cmd_count++;
			// printf("sa\n");
			i = 0;
			while (i < min_idx - 1)
			{
				ps_push(stack_b, stack_a); cmd_count++;
				// printf("pa\n");
				ps_swap(stack_a); cmd_count++;
				// printf("sa\n");
				i++;
			}
		}
		ps_rotate(stack_a); cmd_count++;
		// printf("ra\n");
		sorted++;
	}
	return (cmd_count);
}
