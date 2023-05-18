/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by tanas             #+#    #+#             */
/*   Updated: 2023/05/18 15:31:09 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

void	swap_ops(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		swap_nodes(stack_a);
		ft_printf("sa\n");
	}
	else if (c == 'b')
	{
		swap_nodes(stack_b);
		ft_printf("sb\n");
	}
	else if (c == 's')
	{
		swap_nodes(stack_a);
		swap_nodes(stack_b);
		ft_printf("ss\n");
	}
}
