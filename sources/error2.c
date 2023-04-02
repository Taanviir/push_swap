/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:49:57 by tanas             #+#    #+#             */
/*   Updated: 2023/04/02 16:50:13 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_ps(int err, int argc, char **strings)
{
	if (argc == 2)
		free_double_ptr((void **) strings);
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
