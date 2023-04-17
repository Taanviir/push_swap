/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:11:51 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 13:55:59 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack **stack, t_stack **last)
{
	t_stack		*first;

	first = (*stack);
	(*stack) = (*stack)->next;
	first->next = NULL;
	(*last)->next = first;
}

void	ra(t_stack **stack_a, t_stack **last)
{
	rotate_nodes(stack_a, last);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b, t_stack **last)
{
	rotate_nodes(stack_b, last);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_stack **last)
{
	rotate_nodes(stack_a, last);
	rotate_nodes(stack_b, last);
	ft_printf("rr\n");
}
