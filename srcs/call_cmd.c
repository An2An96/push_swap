/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:27 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/25 13:33:16 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_dispatcher.h"
#include "flags.h"
#include "operations.h"

int	call_cmd(
	char *cmd, t_push_swap *data, char flags)
{
	int i;
	char *tmp;
	char *res;

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
			// data->commands++;
			if (!(flags & FLAG_NO_OUTPUT))
			{
				tmp = ft_strjoin(cmd, "\n");
				res = ft_strjoin(data->commands, tmp);
				free(tmp);
				free(data->commands);
				data->commands = res;
				// ft_putstr(cmd);
				// ft_putchar('\n');
			}
			if (flags & FLAG_DEBUG)
			{
				show_stacks(data->stack_a, data->stack_b);
				// ft_printf("stack a:\n");
				// ft_lstiter(*stack_a, print_stack_el);
				// ft_printf("stack b:\n");
				// ft_lstiter(*stack_b, print_stack_el);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
