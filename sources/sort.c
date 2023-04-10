/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:48:52 by tanas             #+#    #+#             */
/*   Updated: 2023/04/10 17:42:55 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1	3	2	sa->	3	1	2	ra->	1	2	3
3	2	1 	sa->	2	3	1	rra->	1	2	3
2	3	1	rra->	1	2	3
2	1	3 	sa->	1	2	3
3	1	2 	ra->	1	2	3
*/

void	sort_three(t_stack *stack_a)
{
	if (stack_a->data > stack_a->last->data)
	{
		sa(&stack_a->data, &stack_a->next->data, 0);
		
	}
}