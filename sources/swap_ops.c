/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 17:11:20 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_stack **stack)
{
	t_stack	*cur;

	cur = (*stack);
	if ((*stack) && (*stack)->next)
	{
		(*stack) = (*stack)->next;
		cur->next = (*stack)->next;
		(*stack)->next = cur;
	}
}

void	sa(t_stack **stack_a)
{
	swap_nodes(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_printf("ss\n");
}
