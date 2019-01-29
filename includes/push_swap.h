/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:48:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/29 18:00:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

# include "flags.h"
# include "operations.h"
# include "call_cmd.h"
# include "stack.h"

# define	INT_CONTENT(a)	*((int*)a->content)

int		read_args(int argc, char **argv, t_stack *stack, char *flags);
int		read_args_helper(char **values, t_stack *stack);
int		check_value(t_stack *stack, int value, int *error);
int		check_duplicate(t_stack *stack, int value);

int		quick_sort(t_push_swap *data, char flags);
void	insertion_sort(int *arr, int len);
long	ps_atoi(const char *str);

#endif