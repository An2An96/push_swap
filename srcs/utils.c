/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:55 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:10:55 by rschuppe         ###   ########.fr       */
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

int		is_stack_sorted(t_stack *stack)
{
	int i;

	i = stack->len;
	while (--i > 0)
		if (stack->head[i] < stack->head[i - 1])
			return (0);
	return (1);
}
