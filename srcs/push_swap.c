/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:52:34 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:03:01 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack, char flags)
{
	t_push_swap ps_data;

	ps_data.stack_a = stack;
	ps_data.stack_b = ft_stack_new(stack->size);
	ps_data.units_sizes = NULL;
	ps_data.sorted = 0;
	ps_data.commands = ft_strnew(0);
	quick_sort(&ps_data, flags);
	ft_putstr(ps_data.commands);
	ft_strdel(&ps_data.commands);
	stack_delete(ps_data.stack_a);
	stack_delete(ps_data.stack_b);
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
