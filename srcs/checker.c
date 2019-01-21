/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:49:20 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 18:20:29 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_stack(t_list *stack_head)
{
	while (stack_head && stack_head->next)
	{
		if (*((int*)stack_head->content) > *((int*)(stack_head->next)->content))
			return (0);
		stack_head = stack_head->next;
	}
	return (1);
}

t_list	*read_args(int argc, char **argv)
{
	int		i;
	char	**res;
	t_list	*res_stack;
	int		*tmp;

	res_stack = NULL;
	while (--argc)
	{
		res = ft_strsplit(argv[argc], ' ');
		i = 0;
		while (res[i])
		{
			tmp = malloc(sizeof(int));
			*tmp = ft_atoi(res[i]);
			ft_lstadd(&res_stack, ft_lstnew(tmp, sizeof(int)));
			i++;
		}
	}
	return (res_stack);
}

int		handle_cmds_stream(t_list *stack_a)
{
	char	*buf;
	t_list	*stack_b;

	stack_b = NULL;
	while (get_next_line(0, &buf) > 0)
		call_ps_cmd(buf, &stack_a, &stack_b, FLAG_NO_OUTPUT);
	return (!stack_b && check_stack(stack_a));
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		write(1, handle_cmds_stream(read_args(argc, argv)) ? "OK\n" : "KO", 3);
	return (0);
}
