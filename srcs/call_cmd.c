/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:27 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:17:14 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_dispatcher.h"
#include "flags.h"
#include "operations.h"

static void	call_cmd_helper(char *cmd, t_push_swap *data, char flags)
{
	char	*tmp[2];

	if (!(flags & FLAG_NO_OUTPUT))
	{
		tmp[0] = ft_strjoin(cmd, "\n");
		tmp[1] = ft_strjoin(data->commands, tmp[0]);
		free(tmp[0]);
		free(data->commands);
		data->commands = tmp[1];
	}
	if (flags & FLAG_DEBUG)
		show_stacks(data->stack_a, data->stack_b);
}

int			call_cmd(char *cmd, t_push_swap *data, char flags)
{
	int		i;
	char	*tmp;
	char	*res;

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
