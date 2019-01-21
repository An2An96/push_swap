/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:55 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/21 17:17:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void print_stack_el(t_list *el)
{
	ft_printf("%d\n", *((int*)(el->content)));
}

t_list *new_stack_el(t_list *el)
{
	int *content;

	content = (int*)malloc(sizeof(int));
	*content = *((int*)(el->content));
	return (ft_lstnew(content, sizeof(int)));
}

void	del_stack_el(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}