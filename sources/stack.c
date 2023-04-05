/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 17:06:26 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// linked list made with new nodes being added to the top
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

// filling up stack A by placing first number at the end of the list and
// last number on the top of the list
void	fill_stack_a(t_stack **stack_a, char **nums_strings, int argc)
{
	int	*numbers;
	int	arr_len;
	int	i;

	arr_len = 0;
	while (nums_strings[arr_len])
		arr_len++;
	numbers = malloc(sizeof(int) * arr_len);
	if (!numbers)
		ft_error_ps(ERR_MALLOC_FAIL, argc, nums_strings);
	i = -1;
	while (++i < arr_len)
		numbers[i] = ft_atoi(nums_strings[i]);
	if (nums_are_sorted(numbers, arr_len))
	{
		free(numbers);
		return ;
	}
	i = -1;
	while (++i < arr_len)
		add_node_to_top(stack_a, numbers[i]);
	free(numbers);
}
