/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 18:01:21 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1	3	2	sa->	3	1	2	ra->	1	2	3
3	2	1 	sa->	2	3	1	rra->	1	2	3
2	1	3 	sa->	1	2	3
3	1	2 	ra->	1	2	3
2	3	1	rra->	1	2	3
*/

int	get_max_index(int a, int b, int c)
{
	if (a > b && a > c)
		return (1);
	else if (b > a && b > c)
		return (2);
	else if (c > b && c > b)
		return (3);
	return (0);
}

void	sort_three(t_stack **stack_a, t_stack **last)
{
	int	a = (*stack_a)->data;
	int	b = (*stack_a)->next->data;
	int	c = (*last)->data;

	int index = get_max_index(a, b, c);

	if (index == 1)
	{
		sa(stack_a);
		print_list(*stack_a);
		ra(stack_a, last);
	}
	
}
