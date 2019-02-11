/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:50:59 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/10 13:09:00 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct	s_stack
{
	int			*head;
	int			len;
	int			size;
}				t_stack;

t_stack			*ft_stack_new(int size);
void			extend_stack(t_stack *stack, int add_size);
void			stack_push(t_stack *stack, int value);
int				stack_pop(t_stack *stack, int *value);
t_stack			*stack_copy(t_stack *src);
void			stack_delete(t_stack *stack);

#endif
