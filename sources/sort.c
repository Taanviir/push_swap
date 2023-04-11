/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/04/11 16:37:00 by tanas            ###   ########.fr       */
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

void	sort_three(t_stack **stack_a)
{
	int	a = (*stack_a)->data;
	int	b = (*stack_a)->next->data;
	int	c = (*stack_a)->next->next->data;
	if (a > b)
		sa(stack_a);
	if (a > b && b < c)
		ra(stack_a);
}
