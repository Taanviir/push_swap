/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:03:35 by tanas             #+#    #+#             */
/*   Updated: 2023/05/01 16:04:37 by tanas            ###   ########.fr       */
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
