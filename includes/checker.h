/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:31:09 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:24:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"

# include "stack.h"

# define FROM_A_TO_B		0
# define FROM_B_TO_A		1
# define CALL_BOTH			2

# define FLAG_NO_OUTPUT		1
# define FLAG_DEBUG			2

typedef struct	s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list		*units_sizes;
	int			sorted;
	char		*commands;
}				t_push_swap;

typedef struct	s_cmd {
	char		cmd[4];
	void		(*f)(t_stack *, t_stack *);
	char		type_args;
}				t_cmd;

/*
**	Call push_swap command
*/
int				call_cmd(char *cmd, t_push_swap *data, char flags);

/*
**	Push swap operations
*/
void			ps_swap(t_stack *stack_head, t_stack *stack_undef);
void			ps_push(t_stack *stack_head_src, t_stack *stack_head_dst);
void			ps_rotate(t_stack *stack_head, t_stack *stack_undef);
void			ps_reverse_rotate(t_stack *stack_head, t_stack *stack_undef);

/*
**	Utils functions
*/
void			insertion_sort(int *arr, int len);
long			ps_atoi(const char *str);
void			show_stacks(t_stack *stack_a, t_stack *stack_b);
int				is_stack_sorted(t_stack *stack, int bound, int direction);
void			del_unit(void *content, size_t content_size);

#endif
