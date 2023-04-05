/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:01:22 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 15:32:56 by tanas            ###   ########.fr       */
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
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	current = stack;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// freeing a stack after sorting
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*stack = NULL;
}
