/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:01:22 by tanas             #+#    #+#             */
/*   Updated: 2023/04/30 16:16:34 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks to see if numbers are already sorted
int	nums_are_sorted(int *numbers, int arr_len)
{
	int	i;

	i = -1;
	while (++i < (arr_len - 1))
		if (numbers[i] > numbers[i + 1])
			return (0);
	free(numbers);
	return (1);
}

// checks to see if numbers are already sorted
int	stack_is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next != stack)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

// freeing a stack after sorting
void	free_stack(t_stack **stack, int stack_size)
{
	t_stack	*current;
	t_stack	*previous;

	if (*stack == NULL)
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
