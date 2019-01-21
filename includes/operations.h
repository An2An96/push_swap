/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:47:53 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 17:16:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include "ft_printf.h"

void	print_stack_el(t_list *el);
t_list	*new_stack_el(t_list *el);
void	del_stack_el(void *content, size_t content_size);

void	ps_swap(t_list **stack_head, t_list **stack_undef);
void	ps_push(t_list **stack_head_src, t_list **stack_head_dst);
void	ps_rotate(t_list **stack_head, t_list **stack_undef);
void	ps_reverse_rotate(t_list **stack_head, t_list **stack_undef);

#endif
