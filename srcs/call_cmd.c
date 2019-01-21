/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:27 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 15:33:33 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_dispatcher.h"

int	call_ps_cmd(
	char *cmd, t_list **stack_a, t_list **stack_b, int *cmd_count)
{
	int i;

	i = 0;
	while (g_ps_cmds[i].f)
	{
		if (ft_strcmp(cmd, g_ps_cmds[i].cmd) == 0)
		{
			if (g_ps_cmds[i].type_args == FROM_A_TO_B)
				g_ps_cmds[i].f(stack_a, stack_b);
			else if (g_ps_cmds[i].type_args == FROM_B_TO_A)
				g_ps_cmds[i].f(stack_b, stack_a);
			else
			{
				g_ps_cmds[i].f(stack_a, stack_b);
				g_ps_cmds[i].f(stack_b, stack_a);
			}
			if (cmd_count)
			{
				(*cmd_count)++;
				ft_putstr(cmd);
				ft_putchar('\n');
			}
			return (1);
		}
		i++;
	}
	return (0);
}
