/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 14:01:19 by tanas            ###   ########.fr       */
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

void	sort_three(t_stack **stack_a, t_stack **last)
{
	int	a = (*stack_a)->data;
	int	b = (*stack_a)->next->data;
	int	c = (*stack_a)->next->next->data;
	if (a > b && b > c && c < a)
		sa(stack_a);
	if (a > b && b < c && c < a)
		ra(stack_a, last);
}
