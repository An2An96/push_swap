/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:18:41 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:19:59 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

void	show_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_stack_sorted(t_stack *stack);

#endif
