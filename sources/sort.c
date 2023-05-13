/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/05/13 22:55:10 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->next->data < (*stack_a)->next->next->data)
		{
			if ((*stack_a)->data > (*stack_a)->next->next->data)
				rotate_stack(stack_a, NULL, 'a');
			else
				swap_ops(stack_a, NULL, 'a');
		}
		else
		{
			swap_ops(stack_a, NULL, 'a');
			reverse_rotate_stack(stack_a, NULL, 'a');
		}
	}
	else
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
			reverse_rotate_stack(stack_a, NULL, 'a');
		else
		{
			swap_ops(stack_a, NULL, 'a');
			rotate_stack(stack_a, NULL, 'a');
		}
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = 0;
	while (((stack_size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_size)
		{
			num = (*stack_a)->data;
			if (((num >> i) & 1) == 1)
				rotate_stack(stack_a, NULL, 'a');
			else
				push_ops(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b)
			push_ops(stack_a, stack_b, 'a');
		i++;
	}
}
