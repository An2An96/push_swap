/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:14:27 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 17:17:44 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_dispatcher.h"
#include "flags.h"
#include "operations.h"
#include <stdio.h>

int	call_ps_cmd(
	char *cmd, t_list **stack_a, t_list **stack_b, char flags)
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
			if (!(flags & FLAG_NO_OUTPUT))
			{
				ft_putstr(cmd);
				ft_putchar('\n');
			}
			if (flags & FLAG_DEBUG)
			{
				ft_printf("stack a:\n");
				ft_lstiter(*stack_a, print_stack_el);
				ft_printf("stack b:\n");
				ft_lstiter(*stack_b, print_stack_el);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
