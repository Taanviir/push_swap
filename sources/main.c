/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:38:19 by tanas             #+#    #+#             */
/*   Updated: 2023/05/21 17:29:50 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack *current = stack;
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != stack);
	printf("\n\n");
}

void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size == 2)
		swap_ops(a, NULL, 'a');
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size == 5)
		sort_five(a, b);
	else if (stack_size > 5)
		radix_sort(a, b, stack_size);
}

int	main(int argc, char **argv)
{
	char	**validated_args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (ERR_NO_PARAMS);
	argv++;
	validated_args = argv_check(argv, argc);
	stack_size = get_arr_size(validated_args);
	fill_stack_a(&stack_a, validated_args, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);

	// printf("after sort\n");
	// print_list(stack_a);

	free_double_ptr((void **) validated_args);
	free_stack(&stack_a, stack_size);
}
