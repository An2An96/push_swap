/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:47:53 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/25 12:54:23 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include "ft_printf.h"
# include "stack.h"

typedef struct	s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*units_sizes;
	int		sorted;
	char	*commands;
}				t_push_swap;

void	print_stack_el(t_list *el);
t_list	*new_stack_el(t_list *el);
void	del_stack_el(void *content, size_t content_size);
int		is_stack_sorted(t_stack *stack);
void	show_stacks(t_stack *stack_a, t_stack *stack_b);

void	ps_swap(t_stack *stack_head, t_stack *stack_undef);
void	ps_push(t_stack *stack_head_src, t_stack *stack_head_dst);
void	ps_rotate(t_stack *stack_head, t_stack *stack_undef);
void	ps_reverse_rotate(t_stack *stack_head, t_stack *stack_undef);

#endif
