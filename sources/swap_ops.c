/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by tanas             #+#    #+#             */
/*   Updated: 2023/04/10 16:52:35 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa and sb
void	sa(int *a1, int *a2, int print)
{
	*a1 = *a1 - *a2;
	*a2 = *a1 + *a2;
	*a1 = *a2 - *a1;
	if (!print)
		ft_printf("sa\n");
}

void	sb(int *b1, int *b2, int print)
{
	*b1 = *b1 - *b2;
	*b2 = *b1 + *b2;
	*b1 = *b2 - *b1;
	if (!print)
		ft_printf("sb\n");
}

// ss
void	ss(int *a1, int *a2, int *b1, int *b2)
{
	sa(a1, a2, 1);
	sb(b1, b2, 1);
	ft_printf("ss\n");
}
