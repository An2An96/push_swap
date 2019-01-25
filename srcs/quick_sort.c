/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:52:04 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/25 13:37:50 by rschuppe         ###   ########.fr       */
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
	int		i;

	if (data->units_sizes)
	{
		// t_list *cur = data->units_sizes;
		// while (cur)
		// {
		// 	ft_printf("%d ", INT_CONTENT(cur));
		// 	cur = cur->next;
		// }

		flag = INT_CONTENT(data->units_sizes) > 1;
		while (data->units_sizes
			&& ((i = INT_CONTENT(data->units_sizes)) == 1 || flag))
		{
			// ft_printf("\nmove back block %d els (flag: %d)\n", i, flag);
			if (i == 1)
				data->sorted++;
			while (i--)
				call_cmd("pa", data, flags);
			next = data->units_sizes->next;
			ft_lstdelone(&data->units_sizes, del_unit);
			data->units_sizes = next;
			if (data->units_sizes)
				flag = (!flag && INT_CONTENT(data->units_sizes) > 1);
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
