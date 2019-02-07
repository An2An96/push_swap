/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:52:04 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/07 16:25:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	special_handler_for_3_elements(t_push_swap *data, char flags)
{
	if (data->stack_a->head[0] > data->stack_a->head[1]
		&& data->stack_a->head[1] > data->stack_a->head[2])
	{
		call_cmd("sa", data, flags);
		call_cmd("rra", data, flags);
	}
	else if (data->stack_a->head[0] > data->stack_a->head[1]
		&& data->stack_a->head[1] < data->stack_a->head[2])
	{
		if (data->stack_a->head[0] < data->stack_a->head[2])
			call_cmd("sa", data, flags);
		else
			call_cmd("ra", data, flags);
	}
	else if (data->stack_a->head[0] < data->stack_a->head[1]
		&& data->stack_a->head[1] > data->stack_a->head[2])
	{
		if (data->stack_a->head[0] < data->stack_a->head[2])
		{
			call_cmd("rra", data, flags);
			call_cmd("sa", data, flags);
		}
		else
			call_cmd("rra", data, flags);
	}
}

static int	partition_stack_b_helper(t_push_swap *data, char flags)
{
	int unit_size;
	int moved;
	int i;

	unit_size = INT_CONTENT(data->units_sizes);
	if (unit_size > 2)
		moved = partition(data, 'b', unit_size, flags);
	else
	{
		moved = unit_size;
		if (unit_size == 1)
			data->sorted++;
		i = unit_size;
		while (--i >= 0)
			call_cmd("pa", data, flags);
	}
	return (unit_size - moved);
}

void		partition_stack_b(t_push_swap *data, char flags)
{
	t_list	*next;
	char	flag;
	int		rest;

	if (data->stack_b->len && data->units_sizes)
	{
		flag = INT_CONTENT(data->units_sizes) > 1;
		while (INT_CONTENT(data->units_sizes) == 1 || flag)
		{
			rest = partition_stack_b_helper(data, flags);
			if (rest)
			{
				*((int*)data->units_sizes->content) = rest;
				break ;
			}
			else
			{
				next = data->units_sizes->next;
				ft_lstdelone(&data->units_sizes, del_unit);
				if (!(data->units_sizes = next))
					break ;
				flag = (!flag && INT_CONTENT(data->units_sizes) > 1);
			}
		}
	}
}

static void	partition_stack_a_helper(t_push_swap *data, char flags)
{
	int not_sorted;

	not_sorted = data->stack_a->len - data->sorted;
	if (not_sorted == 1)
		data->sorted++;
	else if (not_sorted == 2)
	{
		if (data->stack_a->head[0] > data->stack_a->head[1])
			call_cmd("sa", data, flags);
		data->sorted += 2;
	}
	else if (not_sorted == 3)
	{
		special_handler_for_3_elements(data, flags);
		data->sorted += 3;
	}
}

void		partition_stack_a(t_push_swap *data, char flags)
{
	int		unit;
	t_list	*new;

	while (data->stack_a->len - data->sorted > 2 + (data->sorted == 0))
	{
		if (is_stack_sorted(data->stack_a, data->stack_a->len, 1))
			data->sorted = data->stack_a->len;
		else
		{
			unit = partition(data, 'a',
				data->stack_a->len - data->sorted, flags);
			if (!(new = ft_lstnew(&unit, sizeof(int))))
				exit(-1);
			ft_lstadd(&data->units_sizes, new);
		}
	}
	partition_stack_a_helper(data, flags);
}
