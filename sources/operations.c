/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by tanas             #+#    #+#             */
/*   Updated: 2023/03/20 17:08:48 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa and sb
void	sa(int *a1, int *a2)
{
	*a1 = *a1 - *a2;
	*a2 = *a1 + *a2;
	*a1 = *a2 - *a1;
	ft_printf("sa\n");
}

void	sb(int *b1, int *b2)
{
	int	temp;

	temp = *b1;
	*b1 = *b2;
	*b2 = temp;
	ft_printf("sb\n");
}

// ss
void	ss(int *a1, int *a2, int *b1, int *b2)
{
	sa(a1, a2);
	sb(b1, b2);
	ft_printf("ss\n");
}
