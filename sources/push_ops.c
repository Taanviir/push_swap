/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:11:52 by tanas             #+#    #+#             */
/*   Updated: 2023/04/17 16:40:52 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nodes(t_stack **source, t_stack **destination)
{
	t_stack	*temp;

	if (*source)
	{
		temp = (*source)->next;
		(*source)->next = (*destination);
		(*destination) = (*source);
		(*source) = temp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_nodes(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_nodes(stack_b, stack_a);
	ft_printf("pb\n");
}
