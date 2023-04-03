/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:49:57 by tanas             #+#    #+#             */
/*   Updated: 2023/04/03 17:25:07 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *numbers, int arr_len)
{
	int	i;

	i = -1;
	while (++i < (arr_len - 1))
		if (numbers[i] > numbers[i + 1])
			return (0);
	return (1);
}

void	ft_error_ps(int err, int argc, char **num_strings)
{
	if (argc == 2)
		free_double_ptr((void **) num_strings);
	ft_putendl_fd("Error", 2);
	exit(err);
}

int	check_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && (argv[i] == ' ' || argv[i] == '\t'))
		i++;
	if (argv[i] != '\0')
		return (1);
	return (0);
}
