/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:49:57 by tanas             #+#    #+#             */
/*   Updated: 2023/05/25 13:51:36 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_prog(int err, char **strings, void *arr, t_stack **stack)
{
	free(arr);
	free_double_ptr((void **) strings);
	if (stack)
		free_stack(stack, get_stack_size(*stack));
	if (err > 0)
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

// joins args from '3 2 1 "4 5 6"' to '3 2 1 4 5 6 '
char	**join_args(char **argv, int argc)
{
	char	**strings;
	char	*values;
	int		i;

	values = ft_strdup("");
	i = -1;
	while (++i < argc)
	{
		if (!check_empty(argv[i]))
		{
			ft_putendl_fd("Error", 2);
			free(values);
			exit(ERR_EMPTY_ARG);
		}
		values = ft_strjoin(values, argv[i]);
	}
	strings = ft_split(values, ' ');
	free(values);
	return (strings);
}
