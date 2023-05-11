/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/04/30 16:26:44 by tanas            ###   ########.fr       */
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
	{
		free_double_ptr((void **) num_strings);
		exit(0);
	}
	return (numbers);
}

// linked list made with new nodes being added to the top
// pointer to new node returned
void	add_node_bottom(t_stack **head, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = num;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = (*head)->prev;
		(*head)->prev->next = new_node;
		(*head)->prev = new_node;
	}
}

// filling up stack A by placing first number at the beginning of the list and
// last number at the bottom of the list
void	fill_stack_a(t_stack **stack_a, int *numbers, int stack_size)
{
	int		i;

	(*stack_a) = NULL;
	i = -1;
	while (++i < stack_size)
		add_node_bottom(stack_a, numbers[i]);
	free(numbers);
	if (stack_is_sorted(*stack_a))
	{
		free_stack(stack_a, stack_size);
		exit(0);
	}
}
