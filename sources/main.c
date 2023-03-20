/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:29 by tanas             #+#    #+#             */
/*   Updated: 2023/03/20 18:40:42 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	int num = 1;
	int num2 = 11;
	t_list	*first = ft_lstnew(&num);
	if (!first)
	{
		ft_printf("Stack Overflow.\n");
		// return (NULL);
	}
	t_list	*top = ft_lstnew(&num2);
	ft_lstadd_front(&first, top);
	return (0);
}
