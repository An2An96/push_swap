/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:36:40 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/11 16:01:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			draw_background(t_visualizer *visualizer)
{
	int x;
	int y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			mlx_pixel_put(visualizer->mlx_ptr, visualizer->win_ptr,
				x, y, (x < WIN_WIDTH / 2) ? COLOR_BG_LEFT : COLOR_BG_RIGHT);
			y++;
		}
		x++;
	}
}

void			visualizer_draw_stack(
	t_visualizer *visualizer, t_stack *stack, char stack_name)
{
	int i;
	int cur_pos[2];
	int tmp_pos[2];
	int line_width;

	i = -1;
	cur_pos[1] = 0;
	while (++i < stack->len)
	{
		line_width = ceil(visualizer->value_width * ABS(stack->head[i]));
		cur_pos[0] =
			(STACK_WIDTH / 2) * (stack_name == 'a' ? 1 : 3) - (line_width / 2);
		cur_pos[1] = floor(visualizer->line_height * i);
		tmp_pos[0] = -1;
		while (++tmp_pos[0] < line_width)
		{
			tmp_pos[1] = -1;
			while (++tmp_pos[1] < ceil(visualizer->line_height))
			{
				mlx_pixel_put(visualizer->mlx_ptr, visualizer->win_ptr,
					cur_pos[0] + tmp_pos[0], cur_pos[1] + tmp_pos[1],
					stack->head[i] < 0 ? COLOR_NEGATIVE : COLOR_POSITIVE);
			}
		}
	}
}

t_visualizer	*visualizer_init(t_stack *stack)
{
	int				i;
	int				max;
	t_visualizer	*data;

	data = (t_visualizer*)malloc(sizeof(t_visualizer));
	max = INT_MIN;
	i = 0;
	while (i < stack->len)
	{
		if (ABS(stack->head[i]) > max)
			max = ABS(stack->head[i]);
		i++;
	}
	data->value_width = ((float)WIN_WIDTH / 2.0) / (float)max;
	data->line_height = (float)WIN_HEIGHT / (float)stack->len;
	data->mlx_ptr = mlx_init();
	data->win_ptr =
		mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Push_Swap");
	mlx_do_key_autorepeaton(data->mlx_ptr);
	return (data);
}

int				visualizer_hook(t_push_swap *data)
{
	static char finish;
	char		*buf;

	if (finish)
		return (1);
	if (get_next_line(0, &buf) > 0)
	{
		if (!call_cmd(buf, data, FLAG_NO_OUTPUT))
		{
			write(1, "Error\n", 6);
			ft_close(data);
		}
		else
		{
			draw_background(data->visualizer);
			visualizer_draw_stack(data->visualizer, data->stack_a, 'a');
			visualizer_draw_stack(data->visualizer, data->stack_b, 'b');
		}
		return (1);
	}
	write(1, !(data->stack_b->len)
		&& is_stack_sorted(data->stack_a, data->stack_a->len, 1)
		? "OK\n" : "KO\n", 3);
	finish = 1;
	return (1);
}
