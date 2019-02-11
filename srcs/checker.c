/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:49:20 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/11 16:02:45 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		clear_data(t_push_swap *data)
{
	if (data->visualizer)
	{
		if (data->visualizer->mlx_ptr)
		{
			if (data->visualizer->win_ptr)
				mlx_destroy_window(
					data->visualizer->mlx_ptr,
					data->visualizer->win_ptr);
			free(data->visualizer->mlx_ptr);
		}
		free(data->visualizer);
	}
	stack_delete(data->stack_a);
	stack_delete(data->stack_b);
	free(data);
}

int			ft_close(t_push_swap *data)
{
	clear_data(data);
	exit(0);
	return (0);
}

t_push_swap	*read_args_wrap(int argc, char **argv)
{
	char		flags;
	t_push_swap *data;

	data = (t_push_swap*)malloc(sizeof(t_push_swap));
	data->visualizer = NULL;
	data->stack_a = ft_stack_new(argc - 1);
	data->stack_b = NULL;
	if (!read_args(argc, argv, data->stack_a, &flags))
	{
		write(1, "Error\n", 6);
		ft_close(data);
	}
	data->stack_b = ft_stack_new(data->stack_a->size);
	if (flags & FLAG_DEBUG)
	{
		data->visualizer = visualizer_init(data->stack_a);
		mlx_hook(data->visualizer->win_ptr, 17, 1L << 17, ft_close, data);
		mlx_loop_hook(data->visualizer->mlx_ptr, visualizer_hook, data);
		draw_background(data->visualizer);
		visualizer_draw_stack(data->visualizer, data->stack_a, 'a');
		visualizer_draw_stack(data->visualizer, data->stack_b, 'b');
		mlx_loop(data->visualizer->mlx_ptr);
	}
	return (data);
}

int			handle_cmds_stream(t_push_swap *data)
{
	char	*buf;
	int		res;

	if (!data)
	{
		write(1, "Error\n", 6);
		ft_close(data);
	}
	while (get_next_line(0, &buf) > 0)
	{
		if (!call_cmd(buf, data, FLAG_NO_OUTPUT))
		{
			write(1, "Error\n", 6);
			ft_close(data);
		}
	}
	res = (!(data->stack_b->len)
		&& is_stack_sorted(data->stack_a, data->stack_a->len, 1));
	clear_data(data);
	return (res);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		write(1, handle_cmds_stream(read_args_wrap(argc, argv))
			? "OK\n" : "KO\n", 3);
	return (0);
}
