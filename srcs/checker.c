/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:49:20 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 15:34:17 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

// void print_stack_el(t_list *el)
// {
// 	printf("%d\n", *((int*)(el->content)));
// }

int	check_stack(t_list *stack_head)
{
	while (stack_head && stack_head->next)
	{
		if (*((int*)stack_head->content) > *((int*)(stack_head->next)->content))
			return (0);
		stack_head = stack_head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*buf;
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

		while (get_next_line(0, &buf) > 0)
		{
			call_ps_cmd(buf, &stack_a, &stack_b, NULL);
		}
		// printf("stack a:\n");
		// ft_lstiter(stack_a, print_stack_el);
		// printf("stack b:\n");
		// ft_lstiter(stack_b, print_stack_el);
		
		write(1, (!stack_b && check_stack(stack_a)) ? "OK\n" : "KO", 3);
	}
	return (0);
}
