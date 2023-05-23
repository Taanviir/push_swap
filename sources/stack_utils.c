/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:01:22 by tanas             #+#    #+#             */
/*   Updated: 2023/05/23 13:51:54 by tanas            ###   ########.fr       */
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

int	find_int_dup(int *numbers)
{
	int	i;
	int	j;

	i = -1;
	while (numbers[++i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
	}
	return (1);
}