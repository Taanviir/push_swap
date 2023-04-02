/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/04/02 15:07:35 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top pointer points to the node at the top of the stack 
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**validated_args;

	argv++;
	validated_args = argv_check(argv, argc);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		free_double_ptr((void **) validated_args);
}
