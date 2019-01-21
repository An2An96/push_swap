/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:21:09 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 15:22:10 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_list **stack_a, t_list **stack_b)
{
	int cmd_count;
	int stack_len;
	int need_sort;

	stack_len = ft_lstlen(*stack_a);
	need_sort = 1;
	cmd_count = 0;
	while (need_sort)
	{
		need_sort = 0;
		while (*stack_a)
		{
			if ((*stack_a)->next && *((int*)(*stack_a)->content) > *((int*)((*stack_a)->next)->content))
			{
				call_ps_cmd("sa", stack_a, stack_b, &cmd_count);
				need_sort = 1;
			}
			call_ps_cmd("pb", stack_a, stack_b, &cmd_count);
		}
		while (*stack_b)
			call_ps_cmd("pa", stack_a, stack_b, &cmd_count);
	}
	return (cmd_count);
}
