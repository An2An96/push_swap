/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:27 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/10 13:27:10 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "cmd_dispatcher.h"

static void	call_cmd_helper(char *cmd, t_push_swap *data, char flags)
{
	if (!(flags & FLAG_NO_OUTPUT))
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
	}
	if (flags & FLAG_DEBUG)
	{
		write(1, "\n", 1);
		show_stacks(data->stack_a, data->stack_b);
		write(1, "\n", 1);
	}
}

int			call_cmd(char *cmd, t_push_swap *data, char flags)
{
	int		i;

	i = 0;
	while (g_ps_cmds[i].f)
	{
		if (ft_strcmp(cmd, g_ps_cmds[i].cmd) == 0)
		{
			if (g_ps_cmds[i].type_args == FROM_A_TO_B)
				g_ps_cmds[i].f(data->stack_a, data->stack_b);
			else if (g_ps_cmds[i].type_args == FROM_B_TO_A)
				g_ps_cmds[i].f(data->stack_b, data->stack_a);
			else
			{
				g_ps_cmds[i].f(data->stack_a, data->stack_b);
				g_ps_cmds[i].f(data->stack_b, data->stack_a);
			}
			call_cmd_helper(cmd, data, flags);
			return (1);
		}
		i++;
	}
	return (0);
}
