/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/05/22 16:28:24 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_min_to_top(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*min_node;
	int		index;

	min_node = *stack_a;
	current = (*stack_a)->next;
	while (current != *stack_a)
	{
		if (current->order < (min_node)->order)
			min_node = current;
		current = current->next;
	}
	current = *stack_a;
	index = 0;
	while (current != min_node && ++index)
		current = current->next;
	while (*stack_a != min_node)
	{
		if (index <= 2)
			rotate_stack(stack_a, NULL, 'a');
		else
			reverse_rotate_stack(stack_a, NULL, 'a');
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	bring_min_to_top(stack_a);
	push_ops(stack_a, stack_b, 'b');
	bring_min_to_top(stack_a);
	push_ops(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push_ops(stack_a, stack_b, 'a');
	push_ops(stack_a, stack_b, 'a');
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = *stack_a;
	current = (*stack_a)->next;
	while (current != *stack_a)
	{
		if (current->order > (max_node)->order)
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
	int	i;
	int	j;
	int	num;
	int	max_bits;

	(*stack_b) = NULL;
	max_bits = 0;
	while (((stack_size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stack_size)
		{
			num = (*stack_a)->order;
			if ((num >> i) & 1)
				rotate_stack(stack_a, NULL, 'a');
			else
				push_ops(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push_ops(stack_a, stack_b, 'a');
	}
}
