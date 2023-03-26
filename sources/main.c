/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/03/26 16:51:05 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top pointer points to the node at the top of the stack 
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	stack_a = NULL;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc > 2) // ./push_swap 1 2 4
	{
		multi_argv_check(argv);
		return 2;
	}
	else if (argc == 2) // ./push_swap "1 2 4"
	{
		single_argv_check(argv[1]);
		return 1;
	}
	return (0);
}
