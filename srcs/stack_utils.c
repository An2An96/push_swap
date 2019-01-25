/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:55 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/25 12:42:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	show_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	while (i < stack_a->len || i < stack_b->len)
	{
		ft_printf("%-4.*d ",
			stack_a->len > i, stack_a->len > i ? stack_a->head[i] : 0);
		ft_printf("%-4.*d\n",
			stack_b->len > i, stack_b->len > i ? stack_b->head[i] : 0);
		i++;
	}
	ft_printf("--- ---\n%-3c %-3c\n", 'a', 'b');
}

void	print_stack_el(t_list *el)
{
	ft_printf("%d\n", *((int*)(el->content)));
}

t_list	*new_stack_el(t_list *el)
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

int		is_stack_sorted(t_stack *stack)
{
	int i;

	i = stack->len;
	while (--i >= 0)
		if (stack->head[i] < stack->head[i - 1])
			return (0);
	return (1);
}
