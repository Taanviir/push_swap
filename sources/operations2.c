/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by tanas             #+#    #+#             */
/*   Updated: 2023/05/04 22:20:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = (*stack)->next;
	if (*stack && (*stack)->next)
	{
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		second->prev->next = second;
		first->next->prev = first;
		*stack = second;
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
