/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/03/25 17:17:05 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top pointer points to the node at the top of the stack 
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	error_check( argv);
	if (argc > 2) // ./push_swap 1 2 4
	{
		return 2;
	}
	else if (argc == 2) // ./push_swap "1 2 4"
	{
		return 1;
	}
	return (0);
}
