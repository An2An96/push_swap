/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:52:34 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 14:18:48 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_el(t_list *el)
{
	printf("%d\n", *((int*)(el->content)));
}

t_list *new_stack_el(t_list *el)
{
	int *content;

	content = (int*)malloc(sizeof(int));
	*content = *((int*)(el->content));
	return (ft_lstnew(content, sizeof(int)));
}

void	del_stack_el(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int cmd_count;
	t_list *copy_stack_a;

	printf("Insertion Sort: ");
	copy_stack_a = ft_lstmap(*stack_a, new_stack_el);
	cmd_count = insertion_sort(&copy_stack_a, stack_b);
	printf("%d commands\n", cmd_count);
	// printf("stack a:\n");
	// ft_lstiter(copy_stack_a, print_stack_el);
	// printf("stack b:\n");
	// ft_lstiter(*stack_b, print_stack_el);
	ft_lstdel(&copy_stack_a, del_stack_el);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	if (argc > 1)
	{
		while (--argc)
		{
			tmp = ft_lstnew(malloc(sizeof(int)), sizeof(int));
			*((int*)tmp->content) = ft_atoi(argv[argc]);
			ft_lstadd(&stack_a, tmp);
		}

		push_swap(&stack_a, &stack_b);
	}
	return (0);
}
