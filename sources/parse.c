/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:09 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 17:29:46 by tanas            ###   ########.fr       */
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
	while (*num == '0')
		num++;
	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) || i > 10)
			return (0);
	if (!sign && (ft_strncmp(num, MAXINT, i) > 0))
		return (0);
	else if (sign && (ft_strncmp(num, MININT, i) > 0))
		return (0);
	return (1);
}

// comparing numbers and checking for duplicates
static int	ft_nbrcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = skip_chars(s1);
	j = skip_chars(s2);
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[j]);
}

// finding duplicates. 0 returned if duplicate found
static int	find_dup(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_nbrcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
	}
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
	char	**nums_strings;
	int		i;
	int		zeroes;

	if (argc == 2 && !check_empty(argv[0]))
		ft_error("", ERR_NO_PARAMS);
	if (argc == 2)
		nums_strings = ft_split(argv[0], ' ');
	else
		nums_strings = argv;
	i = -1;
	zeroes = 0;
	while (nums_strings[++i])
	{
		if (!check_num(nums_strings[i]))
			ft_error_ps(ERR_NON_NUMERIC, argc, nums_strings);
		zeroes += find_zeroes(nums_strings[i]);
	}
	if (zeroes > 1)
		ft_error_ps(ERR_DUPLICATES, argc, nums_strings);
	if (!find_dup(nums_strings))
		ft_error_ps(ERR_DUPLICATES, argc, nums_strings);
	return (nums_strings);
}