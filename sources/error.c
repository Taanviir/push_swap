/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:09 by tanas             #+#    #+#             */
/*   Updated: 2023/03/25 17:15:05 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Check for non-integer inputs
Check if argv number is a number
Check for duplicates
Check if stack is already sorted
*/

int	isnum(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
	}
}

void	error_check(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		// if ()
	}
}