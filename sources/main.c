/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 15:46:48 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(t_stack *stack_a, t_stack *stack_b, int stack_size)
// {
// 	if (stack_size <= 3)
// 		return ;
// }

int	main(int argc, char **argv)
{
	char	**validated_args;
	t_stack	*stack_a;
	// t_stack	*stack_b;
	// int		stack_size;

	if (argc < 2)
		return (ERR_NO_PARAMS);
	argv++;
	validated_args = argv_check(argv, argc);
	stack_a = NULL;
	fill_stack_a(&stack_a, validated_args, argc);
	// stack_b = NULL;
	// stack_size = get_stack_size(stack_a);
	if (argc == 2)
		free_double_ptr((void **) validated_args);
	free_stack(&stack_a);
}
