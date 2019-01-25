/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:46:14 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/24 14:56:24 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int *arr, int len)
{
	int i;
	int j;
	int min_idx;
	int tmp;

	i = 0;
	while (i < len)
	{
		min_idx = i;
		j = min_idx;
		while (++j < len)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		tmp = arr[min_idx];
		j = min_idx - i;
		while (j)
		{
			arr[i + j] = arr[i + j - 1];
			j--;
		}
		arr[i] = tmp;
		i++;
	}
}
