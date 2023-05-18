/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:38:50 by tanas             #+#    #+#             */
/*   Updated: 2023/05/18 18:04:06 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *numbers, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = numbers[end];
	i = start - 1;
	j = start;
	while (++j <= (end - 1))
		if (numbers[j] <= pivot)
		{
			i++;
			ft_swap(&numbers[i], &numbers[j]);
		}
	i++;
	ft_swap(&numbers[i], &numbers[end]);
	return (i);
}

void	quicksort(int *numbers, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(numbers, start, end);
	quicksort(numbers, start, pivot - 1);
	quicksort(numbers, pivot + 1, end);
}
