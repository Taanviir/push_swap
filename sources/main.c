/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/04/11 17:22:35 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	(void) stack_b;
	// else if (stack_size)
}

void print_list(t_stack *head) {
    while (head != NULL) {
		if (!head->next)
    	    printf("%d", head->data);
        else
			printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	char	**validated_args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;
	int		stack_size;

	if (argc < 2)
		return (ERR_NO_PARAMS);
	argv++;
	validated_args = argv_check(argv, argc);
	stack_size = get_stack_size(validated_args);
	numbers = get_numbers(validated_args, stack_size);
	if (!numbers)
		exit(0);
	stack_a = fill_stack_a(numbers, stack_size);
	stack_b = NULL;

	printf("before sorting\n");
	print_list(stack_a);

	push_swap(&stack_a, &stack_b, stack_size);

	printf("\nafter sorting\n");
	print_list(stack_a);

	free_double_ptr((void **) validated_args);
	free_stack(&stack_a);
}
