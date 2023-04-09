/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/04/09 18:14:41 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	if (stack_size <= 3)
		sort_three(stack_a, stack_b);
	// else if (stack_size)
}

int	main(int argc, char **argv)
{
	char	**validated_args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;

	if (argc < 2)
		return (ERR_NO_PARAMS);
	argv++;
	validated_args = argv_check(argv, argc);
	numbers = get_numbers(validated_args, argc);
	stack_a = fill_stack_a(numbers, argc - 1);
	stack_b = NULL;
	//push_swap(stack_a, stack_b, argc - 1);
	if (argc == 2)
		free_double_ptr((void **) validated_args);
	free_stack(&stack_a);
}
