/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/04/03 17:10:15 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_to_top(t_stack **stack_a, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = num;
	new_node->next = *stack_a;
	*stack_a = new_node;
}

t_stack	*fill_stack_a(t_stack *stack_a, char **nums_string, int argc)
{
	int	*numbers;
	int	i;
	int	arr_len;

	arr_len = 0;
	while (nums_string[arr_len])
		arr_len++;
	numbers = malloc(sizeof(int) * arr_len);
	if (!numbers)
		ft_error_ps(ERR_MALLOC_FAIL, argc, nums_string);
	i = -1;
	while (++i < arr_len)
		numbers[i] = ft_atoi(nums_string[i]);
	if (nums_are_sorted(numbers, arr_len))
	{
		free(numbers);
		return (NULL);
	}
	i = -1;
	while (++i < arr_len)
		add_node_to_top(&stack_a, numbers[i]);
	free(numbers);
	return (stack_a);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}