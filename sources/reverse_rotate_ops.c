/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:11:54 by tanas             #+#    #+#             */
/*   Updated: 2023/04/30 15:26:18 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_nodes(t_stack **stack)
{
	t_stack		*second_last;
	t_stack		*first;

	if (stack && (*stack)->next)
	{
		second_last = (*stack)->prev->prev;
		first = (*stack);
		(*stack) = (*stack)->prev;
		(*stack) = second_last;
		(*stack)->next = first;
		(*stack)->next = NULL;	
	}
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_nodes(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_nodes(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	ft_printf("rrr\n");
}
