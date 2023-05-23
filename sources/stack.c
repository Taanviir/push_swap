/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:05 by tanas             #+#    #+#             */
/*   Updated: 2023/05/23 16:14:29 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arr_size(char **args)
{
	int	arr_len;

	arr_len = 0;
	while (args[arr_len])
		arr_len++;
	return (arr_len);
}

// getting all the numbers from argv
static int	*get_numbers(char **num_strings, int arr_len)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * (arr_len + 1));
	if (!numbers)
		ft_error_ps(ERR_MALLOC_FAIL, num_strings);
	i = -1;
	while (++i < arr_len)
		numbers[i] = ft_atoi(num_strings[i]);
	numbers[i] = '\0';
	if (nums_are_sorted(numbers, arr_len))
	{
		free_double_ptr((void **) num_strings);
		exit(0);
	}
	return (numbers);
}

// linked list made with new nodes being added to the top
// pointer to new node returned
static void	add_node_bottom(t_stack **head, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = num;
	if (!(*head))
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
static void	get_order(t_stack **stack_a, int *nums)
{
	int		i;
	t_stack	*current;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	while (1)
	{
		i = 0;
		while (current->data != nums[i])
			i++;
		current->order = i;
		current = current->next;
		if (current == *stack_a)
			break ;
	}
}

// fills stack_a with numbers, sorts numbers array, gets the order for the stack
// then a loop checks for duplicates in the sorted array, finally frees the array
void	fill_stack_a(t_stack **stack_a, char **validated_args, int stack_size)
{
	int	i;
	int	*numbers;

	(*stack_a) = NULL;
	numbers = get_numbers(validated_args, stack_size);
	i = -1;
	while (++i < stack_size)
		add_node_bottom(stack_a, numbers[i]);
	quicksort(numbers, 0, stack_size - 1);
	get_order(stack_a, numbers);
	i = 0;
	while (++i < stack_size)
	{
		if (numbers[i] == numbers[i - 1])
		{
			free(numbers);
			free_stack(stack_a, stack_size);
			ft_error_ps(ERR_DUPLICATES, validated_args);
		}
	}
	free(numbers);
}
