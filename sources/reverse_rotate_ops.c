/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:11:54 by tanas             #+#    #+#             */
/*   Updated: 2023/04/18 17:58:25 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_nodes(t_stack **stack, t_stack **last)
{
	t_stack		*second_last;
	t_stack		*first;

	if (stack && last && (*stack)->next)
	{
		second_last = (*last)->prev;
		first = (*stack);
		(*stack) = (*last);
		(*last) = second_last;
		(*stack)->next = first;
		(*last)->next = NULL;	
	}
}

void	rra(t_stack **stack_a, t_stack **last)
{
	reverse_rotate_nodes(stack_a, last);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, t_stack **last)
{
	reverse_rotate_nodes(stack_b, last);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_stack **last)
{
	reverse_rotate_nodes(stack_a, last);
	reverse_rotate_nodes(stack_b, last);
	ft_printf("rrr\n");
}
