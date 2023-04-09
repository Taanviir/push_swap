/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/04/09 18:14:14 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// linked list made with new nodes being added to the top
static t_stack	*add_node_bottom(t_stack *pointer, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = num;
	new_node->next = NULL;
	pointer->next = new_node;
	return (new_node);
}

// getting all the numbers from argv
int	*get_numbers(char **num_strings, int argc)
{
	int	*numbers;
	int	arr_len;
	int	i;

	arr_len = 0;
	while (num_strings[arr_len])
		arr_len++;
	numbers = malloc(sizeof(int) * arr_len);
	if (!numbers)
		ft_error_ps(ERR_MALLOC_FAIL, argc, num_strings);
	i = -1;
	while (++i < arr_len)
		numbers[i] = ft_atoi(num_strings[i]);
	if (nums_are_sorted(numbers, arr_len))
		return (NULL);
	return (numbers);
}

// filling up stack A by placing first number at the beginning of the list and
// last number at the bottom of the list
t_stack	*fill_stack_a(int *numbers, int arr_len)
{
	t_stack	*stack_a;
	t_stack	*pointer;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->data = numbers[0];
	stack_a->next = NULL;
	pointer = stack_a;
	i = 0;
	while (++i < arr_len)
		pointer = add_node_bottom(pointer, numbers[i]);
	pointer = stack_a;
	free(numbers);
	return (stack_a);
}
