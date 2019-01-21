/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:21:09 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 16:41:47 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_list **stack_a, t_list **stack_b, char flags)
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
			if ((*stack_a)->next
				&& *((int*)(*stack_a)->content)
					> *((int*)((*stack_a)->next)->content))
			{
				cmd_count += call_ps_cmd("sa", stack_a, stack_b, flags);
				need_sort = 1;
			}
			cmd_count += call_ps_cmd("pb", stack_a, stack_b, flags);
		}
		while (*stack_b)
			cmd_count += call_ps_cmd("pa", stack_a, stack_b, flags);
	}
	return (cmd_count);
}
