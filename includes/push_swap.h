/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 15:31:47 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "operations.h"
# include "call_cmd.h"
# include <stdio.h>

int 	bubble_sort(t_list **stack_a, t_list **stack_b);
int		insertion_sort(t_list **stack_a, t_list **stack_b);

#endif