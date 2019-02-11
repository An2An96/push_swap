/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:52:34 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/11 16:00:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap(t_stack *stack, char flags)
{
	int			len;
	t_push_swap data;

	(void)flags;
	data.stack_a = stack;
	data.stack_b = ft_stack_new(stack->size);
	data.units_sizes = NULL;
	data.sorted = 0;
	len = data.stack_a->len;
	while (data.sorted < data.stack_a->len)
	{
		partition_stack_a(&data, flags);
		partition_stack_b(&data, flags);
	}
	ft_lstdel(&(data.units_sizes), del_unit);
	stack_delete(data.stack_a);
	stack_delete(data.stack_b);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	char	flags;

	flags = 0;
	if (argc > 1)
	{
		stack = ft_stack_new(argc - 1);
		if (read_args(argc, argv, stack, &flags))
			push_swap(stack, flags);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
