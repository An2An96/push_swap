/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:58:47 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/11 16:01:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

/*
**	Visualizer macros
*/
# define WIN_WIDTH		(512)
# define WIN_HEIGHT		(512)
# define STACK_WIDTH	(WIN_WIDTH / 2)
# define STACK_HEIGHT	(WIN_HEIGHT)

# define COLOR_BG_LEFT	0x5F91E8
# define COLOR_BG_RIGHT	0x2A5399
# define COLOR_POSITIVE	0xB7D2FF
# define COLOR_NEGATIVE	0x93BBFF

int				ft_close(t_push_swap *data);
void			clear_data(t_push_swap *data);

/*
**	Visualizer functions
*/
t_visualizer	*visualizer_init(t_stack *stack);
void			draw_background(t_visualizer *visualizer);
void			visualizer_draw_stack(
	t_visualizer *visualizer, t_stack *stack, char stack_name);
int				visualizer_hook(t_push_swap *data);

#endif
