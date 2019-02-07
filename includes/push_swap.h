/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/07 16:26:25 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

# include "checker.h"

# define INT_CONTENT(a)	*((int*)a->content)

/*
**	Sort algorithm functions
*/
int		partition(t_push_swap *data, char stack_name, int bound, int flags);
void	partition_stack_a(t_push_swap *data, char flags);
void	partition_stack_b(t_push_swap *data, char flags);

/*
**	Additional functions
*/
void	insertion_sort(int *arr, int len);

#endif
