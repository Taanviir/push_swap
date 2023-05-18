/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/05/18 17:26:39 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = (*stack_a);
	current = (*stack_a)->next;
	while (current != (*stack_a))
	{
		if (current->data > max_node->data)
			max_node = current;
		current = current->next;
	}
	if (*stack_a == max_node)
		rotate_stack(stack_a, NULL, 'a');
	else if ((*stack_a)->next == max_node)
		reverse_rotate_stack(stack_a, NULL, 'a');
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_ops(stack_a, NULL, 'a');
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	max_pos;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_pos = stack_size - 1;
	max_bits = 0;
	while ((max_pos >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stack_size)
		{
			num = (*stack_a)->order;
			if (((num >> i) & 1) == 1)
				rotate_stack(stack_a, NULL, 'a');
			else
				push_ops(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push_ops(stack_a, stack_b, 'a');
	}
}
