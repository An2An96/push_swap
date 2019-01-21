/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:52:34 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 17:18:41 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, char flags)
{
	int cmd_count;
	t_list *copy_stack_a;

	// ft_printf("Insertion Sort: ");
	copy_stack_a = ft_lstmap(*stack_a, new_stack_el);
	cmd_count = insertion_sort(&copy_stack_a, stack_b, flags);
	ft_printf("%d commands\n", cmd_count);
	// ft_printf("stack a:\n");
	// ft_lstiter(copy_stack_a, print_stack_el);
	// ft_printf("stack b:\n");
	// ft_lstiter(*stack_b, print_stack_el);
	ft_lstdel(&copy_stack_a, del_stack_el);

	// ft_printf("Bubble Sort: ");
	// copy_stack_a = ft_lstmap(*stack_a, new_stack_el);
	// cmd_count = bubble_sort(&copy_stack_a, stack_b, flags);
	// ft_printf("%d commands\n", cmd_count);
	// // ft_printf("stack a:\n");
	// // ft_lstiter(copy_stack_a, print_stack_el);
	// // ft_printf("stack b:\n");
	// // ft_lstiter(*stack_b, print_stack_el);
	// ft_lstdel(&copy_stack_a, del_stack_el);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	char **res;
	int i;
	char flags;

	flags = 0;
	if (argc > 1)
	{
		while (--argc)
		{
			if (ft_strcmp(argv[argc], "-v") == 0)
				flags |= FLAG_DEBUG;
			else
			{
				res = ft_strsplit(argv[argc], ' ');
				i = 0;
				while (res[i])
				{
					tmp = ft_lstnew(malloc(sizeof(int)), sizeof(int));
					*((int*)tmp->content) = ft_atoi(res[i]);
					ft_lstadd(&stack_a, tmp);
					i++;
				}
			}
		}
		push_swap(&stack_a, &stack_b, flags);
	}
	return (0);
}
