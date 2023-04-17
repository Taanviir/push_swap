/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 17:05:06 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(char **args)
{
	int	arr_len;

	arr_len = 0;
	while (args[arr_len])
		arr_len++;
	return (arr_len);
}

// getting all the numbers from argv
int	*get_numbers(char **num_strings, int arr_len)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * arr_len);
	if (!numbers)
		ft_error_ps(ERR_MALLOC_FAIL, num_strings);
	i = -1;
	while (++i < arr_len)
		numbers[i] = ft_atoi(num_strings[i]);
	if (nums_are_sorted(numbers, arr_len))
		return (NULL);
	return (numbers);
}

// linked list made with new nodes being added to the top
// pointer to new node returned
static t_stack	*add_node_bottom(t_stack *pointer, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->data = num;
	new_node->next = NULL;
	pointer->next = new_node;
	new_node->prev = pointer;
	return (new_node);
}

// filling up stack A by placing first number at the beginning of the list and
// last number at the bottom of the list
t_stack	*fill_stack_a(int *numbers, int arr_len, t_stack **last_node)
{
	t_stack	*stack_a;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->prev = NULL;
	stack_a->data = numbers[0];
	stack_a->next = NULL;
	(*last_node) = stack_a;
	i = 0;
	while (++i < arr_len && (*last_node))
		(*last_node) = add_node_bottom((*last_node), numbers[i]);
	free(numbers);
	return (stack_a);
}
