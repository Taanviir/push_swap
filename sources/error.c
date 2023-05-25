/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:09 by tanas             #+#    #+#             */
/*   Updated: 2023/05/23 16:09:24 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define MAXINT "2147483647"
#define MININT "2147483648"

// skips the leading zeroes, + and minus then checks for numbers only
// and for number withing limits. 0 returned if invalid num found
static int	check_num(char *num)
{
	int	i;
	int	sign;

	sign = (num[0] == '-');
	num += (*num == '+' || *num == '-');
	if (!(*num))
		return (0);
	while (*num == '0')
		num++;
	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) || i > 10)
			return (0);
	if (i == 10 && !sign && (ft_strncmp(num, MAXINT, i) > 0))
		return (0);
	else if (i == 10 && sign && (ft_strncmp(num, MININT, i) > 0))
		return (0);
	return (1);
}

// finding zeroes and repeating zeroes like 0 00 000
static int	find_zeroes(char *num)
{
	int	i;

	i = 0;
	i += (num[i] == '+' || num[i] == '-');
	while (num[i] && num[i] == '0')
		i++;
	if (num[i] != '\0')
		return (0);
	return (1);
}

// performs all the argv checks and returns the valid args
char	**argv_check(char **argv, int argc)
{
	char	**num_strings;
	int		i;
	int		zeroes;

	if (argc == 2 && !check_empty(argv[0]))
		ft_error("", ERR_NO_PARAMS);
	num_strings = join_args(argv, argc - 1);
	i = -1;
	zeroes = 0;
	while (num_strings[++i])
	{
		if (!check_num(num_strings[i]))
			close_prog(ERR_NON_NUMERIC, num_strings, NULL, NULL);
		zeroes += find_zeroes(num_strings[i]);
	}
	if (zeroes > 1)
		close_prog(ERR_NON_NUMERIC, num_strings, NULL, NULL);
	return (num_strings);
}
