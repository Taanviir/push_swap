/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:49:57 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 15:22:58 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// frees double pointer if argc is 2, prints error message and exits
void	ft_error_ps(int err, int argc, char **num_strings)
{
	if (argc == 2)
		free_double_ptr((void **) num_strings);
	ft_putendl_fd("Error", 2);
	exit(err);
}

// checks to see if empty string is passed
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

// skips + and leading zeroes in a number
int	skip_chars(const char *string)
{
	int	i;

	i = 0;
	while (string[i] == '+' || string[i] == '0')
		i++;
	return (i);
}
