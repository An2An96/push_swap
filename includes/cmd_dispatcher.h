/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_dispatcher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:46 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/23 10:40:23 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

# define	FROM_A_TO_B 0
# define	FROM_B_TO_A 1
# define	CALL_BOTH	2

typedef struct	s_cmd {
	char		cmd[4];
	void		(*f)(t_stack *, t_stack *);
	char		type_args;
}				t_cmd;

t_cmd	g_ps_cmds[] = {
	{ "sa", ps_swap,	FROM_A_TO_B },
	{ "sb", ps_swap,	FROM_B_TO_A },
	{ "ss", ps_swap,	CALL_BOTH },
	{ "pa", ps_push,	FROM_B_TO_A },
	{ "pb", ps_push,	FROM_A_TO_B },
	{ "ra", ps_rotate,	FROM_A_TO_B },
	{ "rb", ps_rotate,	FROM_B_TO_A },
	{ "rr", ps_rotate,	CALL_BOTH },
	{ "rra", ps_reverse_rotate, FROM_A_TO_B },
	{ "rrb", ps_reverse_rotate, FROM_B_TO_A },
	{ "rrr", ps_reverse_rotate, CALL_BOTH },
	{ "", NULL, 0 }
};
