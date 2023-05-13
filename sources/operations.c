/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:03:35 by tanas             #+#    #+#             */
/*   Updated: 2023/05/13 20:39:08 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		*stack_a = (*stack_a)->next;
		ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		*stack_b = (*stack_b)->next;
		ft_printf("rb\n");
	}
	else if (c == 'r')
	{
		*stack_a = (*stack_a)->next;
		*stack_b = (*stack_b)->next;
		ft_printf("rr\n");
	}
}

void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		*stack_a = (*stack_a)->prev;
		ft_printf("rra\n");
	}
	else if (c == 'b')
	{
		*stack_b = (*stack_b)->prev;
		ft_printf("rrb\n");
	}
	else if (c == 'r')
	{
		*stack_a = (*stack_a)->prev;
		*stack_b = (*stack_b)->prev;
		ft_printf("rrr\n");
	}
}

static void	push_node(t_stack **src_stack, t_stack **dst_stack)
{
	t_stack	*top_src;

	if (!(*src_stack))
		return ;
	top_src = *src_stack;
	*src_stack = (*src_stack)->next;
	(*src_stack)->prev = top_src->prev;
	top_src->prev->next = *src_stack;
	if (!(*dst_stack))
	{
		(*dst_stack) = top_src;
		(*dst_stack)->next = top_src;
		(*dst_stack)->prev = top_src;
	}
	else
	{
		top_src->next = (*dst_stack);
		top_src->prev = (*dst_stack)->prev;
		(*dst_stack)->prev->next = top_src;
		(*dst_stack)->prev = top_src;
		*dst_stack = top_src;
	}
	if (*src_stack == top_src)
		*src_stack = NULL;
}

void	push_ops(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		push_node(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		push_node(stack_a, stack_b);
		ft_printf("pb\n");
	}
}
