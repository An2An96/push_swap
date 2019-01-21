/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 17:16:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include "flags.h"
# include "operations.h"
# include "call_cmd.h"

int 	bubble_sort(t_list **stack_a, t_list **stack_b, char flags);
int		insertion_sort(t_list **stack_a, t_list **stack_b, char flags);

#endif