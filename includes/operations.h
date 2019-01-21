/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:47:53 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 15:15:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

void	ps_swap(t_list **stack_head, t_list **stack_undef);
void	ps_push(t_list **stack_head_src, t_list **stack_head_dst);
void	ps_rotate(t_list **stack_head, t_list **stack_undef);
void	ps_reverse_rotate(t_list **stack_head, t_list **stack_undef);

#endif
