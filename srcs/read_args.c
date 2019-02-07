/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:57:03 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:00:34 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_duplicate(t_stack *stack, int value)
{
	int len;
	int i;

	len = stack->len;
	i = 0;
	while (i < len)
	{
		if (stack->head[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int		check_value(t_stack *stack, int value, int *error)
{
	return (*error == 0
		&& (*error = (value > INT_MAX)) == 0
		&& (*error = (value < INT_MIN)) == 0
		&& (*error = (check_duplicate(stack, value))) == 0);
}

int		read_args_helper(char **values, t_stack *stack)
{
	int		i;
	long	value;
	int		error;

	error = 0;
	i = 0;
	while (values[i] && values[i + 1])
		i++;
	extend_stack(stack, i);
	while (i >= 0)
	{
		value = ps_atoi(values[i]);
		if (check_value(stack, value, &error))
			stack_push(stack, value);
		free(values[i]);
		i--;
	}
	free(values);
	return (!error);
}

int		read_args(int argc, char **argv, t_stack *stack, char *flags)
{
	while (--argc)
	{
		if (ft_strcmp(argv[argc], "-v") == 0)
			*flags |= FLAG_DEBUG;
		else if (!read_args_helper(ft_strsplit(argv[argc], ' '), stack))
			return (0);
	}
	return (1);
}