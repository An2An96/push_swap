/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:52:34 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/25 12:59:12 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, char flags)
{
	int cmd_count;
	t_stack *copy_stack_a;

	t_push_swap ps_data;

	ps_data.stack_a = stack_a;
	ps_data.stack_b = stack_b;
	ps_data.units_sizes = NULL;
	ps_data.sorted = 0;
	ps_data.commands = ft_strnew(0);

	// copy_stack_a = stack_copy(stack_a);
	// copy_stack_a = ft_lstmap(*stack_a, new_stack_el);
	quick_sort(&ps_data, flags);
	ft_putstr(ps_data.commands);
	// ft_printf("%d commands\n", ps_data.commands);
	// ft_printf("stack a:\n");
	// ft_lstiter(copy_stack_a, print_stack_el);
	// ft_printf("stack b:\n");
	// ft_lstiter(*stack_b, print_stack_el);
	// ft_lstdel(&copy_stack_a, del_stack_el);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*tmp;
	char **res;
	int i;
	char flags;

	flags = 0;
	if (argc > 1)
	{
		stack_a = ft_stack_new(argc - 1);

		while (--argc)
		{
			if (ft_strcmp(argv[argc], "-v") == 0)
				flags |= FLAG_DEBUG;
			else
			{
				res = ft_strsplit(argv[argc], ' ');

				i = 0;
				while (res[i])
					i++;
				i--;
				extend_stack(stack_a, i);

				while (i >= 0)
				{
					stack_push(stack_a, ft_atoi(res[i]));
					free(res[i]);
					i--;
				}
				free(res);
			}
		}
		stack_b = ft_stack_new(stack_a->size);
		push_swap(stack_a, stack_b, flags);
	}
	return (0);
}
