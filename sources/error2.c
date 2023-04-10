/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:49:57 by tanas             #+#    #+#             */
/*   Updated: 2023/04/10 17:00:18 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// frees double pointer if argc is 2, prints error message and exits
void	ft_error_ps(int err, char **num_strings)
{
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

// joins args from '3 2 1 "4 5 6"' to '3 2 1 4 5 6 '
char	**join_args(char **argv, int argc)
{
	char	**strings;
	char	*values;
	int		i;

	values = ft_strdup("");
	i = -1;
	while (++i < argc)
		values = ft_strjoin(values, argv[i]);
	strings = ft_split(values, ' ');
	free(values);
	return (strings);
}
