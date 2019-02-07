/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:55 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/07 16:24:05 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	insertion_sort(int *arr, int len)
{
	int i;
	int j;
	int min_idx;
	int tmp;

	i = 0;
	while (i < len)
	{
		min_idx = i;
		j = min_idx;
		while (++j < len)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		tmp = arr[min_idx];
		j = min_idx - i;
		while (j)
		{
			arr[i + j] = arr[i + j - 1];
			j--;
		}
		arr[i] = tmp;
		i++;
	}
}

int		ps_atoi(const char *str, long *value)
{
	char	negative;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = 1 - (2 * (str[i] == '-'));
		i++;
	}
	else
		negative = 1;
	*value = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*value = (*value * 10) + (str[i] - '0');
		i++;
	}
	*value = *value * negative;
	return (1);
}

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

int		is_stack_sorted(t_stack *stack, int bound, int direction)
{
	int i;

	i = bound;
	while (--i > 0)
		if ((direction == 1 && stack->head[i] < stack->head[i - 1])
			|| (direction == -1 && stack->head[i] > stack->head[i - 1]))
			return (0);
	return (1);
}

void	del_unit(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}
