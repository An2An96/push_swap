/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/24 14:53:56 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include "flags.h"
# include "operations.h"
# include "call_cmd.h"
# include "stack.h"

# define	INT_CONTENT(a)	*((int*)a->content)

// int 	bubble_sort(t_list **stack_a, t_list **stack_b, char flags);
// int		insertion_sort(t_list **stack_a, t_list **stack_b, char flags);
// int		selection_sort(t_list **stack_a, t_list **stack_b, char flags);
int		quick_sort(t_push_swap *data, char flags);
void	insertion_sort(int *arr, int len);

#endif