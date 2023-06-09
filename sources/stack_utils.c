/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:01:22 by tanas             #+#    #+#             */
/*   Updated: 2023/05/25 13:49:09 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks to see if numbers are already sorted
int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stack(t_stack **stack, int stack_size)
{
	t_stack	*current;
	t_stack	*previous;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (stack_size--)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*stack = NULL;
}

int	get_stack_size(t_stack *stack)
{
	int		counter;
	t_stack	*current;

	if (!stack)
		return (0);
	counter = 1;
	current = stack;
	while (current->next != stack)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
