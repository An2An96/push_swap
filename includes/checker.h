/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:31:09 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/18 16:49:19 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"

void	ps_swap(t_list **stack_head);
void	ps_push(t_list **stack_head_src, t_list **stack_head_dst);
void	ps_rotate(t_list **stack_head);
void	ps_reverse_rotate(t_list **stack_head);

#endif
