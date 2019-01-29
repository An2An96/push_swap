/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:52:04 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 16:54:24 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_unit(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

int		find_median(t_stack *stack, int limit)
{
	int *a;
	int res;
	int len;

	len = stack->len - limit;
	if ((a = (int*)malloc(len * sizeof(int))) == 0)
		exit(1);
	ft_memmove(a, stack->head, len * sizeof(int));
	insertion_sort(a, len);
	res = a[len / 2];
	free(a);
	return (res);
}

void	partition(t_push_swap *data, int pivot, char flags)
{
	int el;
	int *unit_size;
	int ra_count;

	el = data->stack_a->len - data->sorted;
	unit_size = (int*)malloc(sizeof(int));
	*unit_size = 0;
	ra_count = 0;
	while (el--)
	{
		if (*(data->stack_a->head) < pivot)
		{
			call_cmd("pb", data, flags);
			(*unit_size)++;
		}
		else
		{
			call_cmd("ra", data, flags);
			ra_count++;
		}
	}
	if (data->sorted)
		while (ra_count--)
			call_cmd("rra", data, flags);
	ft_lstadd(&data->units_sizes, ft_lstnew(unit_size, sizeof(int)));
}

void	move_back(t_push_swap *data, char flags)
{
	t_list	*next;
	char	flag;
	int		median;
	int		unit_size;
	int		rb_op_count;

	if (data->units_sizes)
	{
		flag = INT_CONTENT(data->units_sizes) > 1;
		while (data->units_sizes
			&& ((unit_size = INT_CONTENT(data->units_sizes)) == 1 || flag))
		{
			rb_op_count = 0;
			if (unit_size == 1)
			{
				data->sorted++;
				call_cmd("pa", data, flags);
			}
			else if (unit_size == 2)
			{
				while (--unit_size >= 0)
					call_cmd("pa", data, flags);
			}
			else
			{
				median = find_median(data->stack_b,
					data->stack_b->len - unit_size);
				while (--unit_size >= 0)
				{
					if (*(data->stack_b->head) < median)
					{
						call_cmd("rb", data, flags);
						rb_op_count++;
					}
					else
					{
						call_cmd("pa", data, flags);
					}
				}
			}
			if (rb_op_count)
			{
				*((int*)data->units_sizes->content) = rb_op_count;
			}
			else
			{
				next = data->units_sizes->next;
				ft_lstdelone(&data->units_sizes, del_unit);
				data->units_sizes = next;
				if (data->units_sizes)
					flag = (!flag && INT_CONTENT(data->units_sizes) > 1);
			}
			if (rb_op_count)
			{
				while (rb_op_count--)
					call_cmd("rrb", data, flags);
				break ;
			}
		}
	}
}

int		quick_sort(t_push_swap *data, char flags)
{
	int len;
	int not_sorted;
	int median;

	len = data->stack_a->len;
	while (data->sorted < len)
	{
		while (data->stack_a->len - data->sorted > 2)
		{
			if (is_stack_sorted(data->stack_a))
				data->sorted = data->stack_a->len;
			else
			{
				median = find_median(data->stack_a, data->sorted);
				partition(data, median, flags);
			}
		}
		not_sorted = data->stack_a->len - data->sorted;
		if (not_sorted == 2)
		{
			if (data->stack_a->head[0] > data->stack_a->head[1])
				call_cmd("sa", data, flags);
			data->sorted += 2;
		}
		else if (not_sorted == 1)
			data->sorted++;
		move_back(data, flags);
	}
	return (1);
}
