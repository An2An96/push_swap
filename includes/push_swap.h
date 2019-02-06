/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/06 20:20:33 by rschuppe         ###   ########.fr       */
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
**	Read and validate functions
*/
int		read_args(int argc, char **argv, t_stack *stack, char *flags);
int		read_args_helper(char **values, t_stack *stack);
int		check_value(t_stack *stack, int value, int *error);
int		check_duplicate(t_stack *stack, int value);

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
