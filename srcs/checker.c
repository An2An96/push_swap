/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:49:20 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/07 16:04:56 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		clear_data(t_push_swap **data)
{
	stack_delete((*data)->stack_a);
	stack_delete((*data)->stack_b);
	free(*data);
	*data = NULL;
}

t_push_swap	*read_args_wrap(int argc, char **argv)
{
	char		flags;
	t_push_swap *data;

	data = (t_push_swap*)malloc(sizeof(t_push_swap));
	data->stack_a = ft_stack_new(argc - 1);
	data->stack_b = ft_stack_new(data->stack_a->size);
	if (!read_args(argc, argv, data->stack_a, &flags))
		clear_data(&data);
	return (data);
}

int			handle_cmds_stream(t_push_swap *data)
{
	char	*buf;
	int		res;

	if (!data)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	while (get_next_line(0, &buf) > 0)
	{
		if (!call_cmd(buf, data, FLAG_NO_OUTPUT))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
	}
	res = (!(data->stack_b->len)
		&& is_stack_sorted(data->stack_a, data->stack_a->len, 1));
	clear_data(&data);
	return (res);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		write(1, handle_cmds_stream(read_args_wrap(argc, argv))
			? "OK\n" : "KO\n", 3);
	return (0);
}
