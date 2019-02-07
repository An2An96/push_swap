/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:49:20 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/07 12:54:00 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_push_swap	*read_args(int argc, char **argv)
{
	int			i;
	char		**res;
	t_push_swap *data;

	data = (t_push_swap*)malloc(sizeof(t_push_swap));
	data->stack_a = ft_stack_new(argc - 1);
	while (--argc)
	{
		res = ft_strsplit(argv[argc], ' ');
		i = 0;
		while (res[i])
			i++;
		i--;
		extend_stack(data->stack_a, i);
		while (i >= 0)
		{
			stack_push(data->stack_a, ft_atoi(res[i]));
			free(res[i]);
			i--;
		}
		free(res);
	}
	data->stack_b = ft_stack_new(data->stack_a->size);
	return (data);
}

int			handle_cmds_stream(t_push_swap *data)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
		call_cmd(buf, data, FLAG_NO_OUTPUT);
	return (!(data->stack_b->len)
		&& is_stack_sorted(data->stack_a, data->stack_a->len, 1));
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		write(1, handle_cmds_stream(read_args(argc, argv)) ? "OK\n" : "KO", 3);
	return (0);
}
