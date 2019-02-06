/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_dispatcher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:46 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:21:11 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_DISPATCHER_H
# define CMD_DISPATCHER_H

# include "checker.h"

t_cmd	g_ps_cmds[] = {
	{ "sa", ps_swap, FROM_A_TO_B },
	{ "sb", ps_swap, FROM_B_TO_A },
	{ "ss", ps_swap, CALL_BOTH },
	{ "pa", ps_push, FROM_B_TO_A },
	{ "pb", ps_push, FROM_A_TO_B },
	{ "ra", ps_rotate, FROM_A_TO_B },
	{ "rb", ps_rotate, FROM_B_TO_A },
	{ "rr", ps_rotate, CALL_BOTH },
	{ "rra", ps_reverse_rotate, FROM_A_TO_B },
	{ "rrb", ps_reverse_rotate, FROM_B_TO_A },
	{ "rrr", ps_reverse_rotate, CALL_BOTH },
	{ "", NULL, 0 }
};

#endif
