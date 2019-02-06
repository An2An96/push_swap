/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:22:18 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:02:51 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pivot(t_stack *stack, int bound)
{
	int *a;
	int res;

	if ((a = (int*)malloc(bound * sizeof(int))) == 0)
		exit(-1);
	ft_memmove(a, stack->head, bound * sizeof(int));
	insertion_sort(a, bound);
	res = a[bound / 2];
	free(a);
	return (res);
}

static int	get_elements_for_push(t_stack *stack, int pivot, int sign)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < stack->len)
	{
		count += ((sign && stack->head[i] > pivot)
			|| (!sign && stack->head[i] < pivot));
		i++;
	}
	return (count);
}

static void	partition_helper(
	t_push_swap *data, char stack_name, int flags, int rotate_count)
{
	if ((stack_name == 'a' && data->sorted)
		|| (stack_name == 'b' && data->units_sizes->next))
		while (rotate_count--)
			call_cmd(stack_name == 'a' ? "rra" : "rrb", data, flags);
}

int			partition(t_push_swap *data, char stack_name, int bound, int flags)
{
	int		counter[2];
	int		pivot;
	int		need_push;
	t_stack	*stack;

	stack = stack_name == 'a' ? data->stack_a : data->stack_b;
	pivot = find_pivot(stack, bound);
	need_push = get_elements_for_push(stack, pivot, stack_name == 'b');
	counter[0] = 0;
	counter[1] = 0;
	while (bound-- && need_push)
	{
		if (((stack_name == 'a' && *(stack->head) < pivot)
			|| (stack_name == 'b' && *(stack->head) > pivot))
			&& need_push-- && ++counter[0])
			call_cmd(stack_name == 'a' ? "pb" : "pa", data, flags);
		else
		{
			call_cmd(stack_name == 'a' ? "ra" : "rb", data, flags);
			counter[1]++;
		}
	}
	partition_helper(data, stack_name, flags, counter[1]);
	return (counter[0]);
}
