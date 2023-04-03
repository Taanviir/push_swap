/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/04/03 16:57:07 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	char	**validated_args;

	if (argc < 2)
		return (ERR_NO_PARAMS);
	argv++;
	stack_a = NULL;
	validated_args = argv_check(argv, argc);
	stack_a = fill_stack_a(stack_a, validated_args, argc);
	// stack_b = NULL;
	if (argc == 2)
		free_double_ptr((void **) validated_args);
	// free stacks
}
