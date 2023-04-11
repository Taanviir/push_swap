/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:11:51 by tanas             #+#    #+#             */
/*   Updated: 2023/04/11 17:17:39 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack **stack)
{
	t_stack    *cur;

	cur = (*stack);
	if ((*stack) && (*stack)->next)
	{
		// (*stack) = (*stack)->prev;
		// cur->next = (*stack)->next;
		// (*stack)->next = cur;
	}
}

void	ra(t_stack **stack_a)
{
	rotate_nodes(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_nodes(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	ft_printf("rr\n");
}
