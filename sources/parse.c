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

static int isnum(char *num)
{
	int	i;
	int	digit_count;
	int	sign_count;

	i = (num[0] == '-' || num[0] == '+');
	sign_count = (num[0] == '-' || num[0] == '+');
	digit_count = 0;
	while (num[++i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		digit_count++;
	}
	if (digit_count > 10)
		return (0);
	else if ((sign_count == 0 && ft_strncmp(num, "2147483647", i) > 0) \
		|| (sign_count == 1 && ft_strncmp(num + 1, "2147483648", i) > 0))
		return (0);
	return (1);
}

// checking for numbers only. 0 returned if non-digit char found
// static int	isnum(char *num)
// {
// 	int	i;

// 	i = -1;
// 	while (num[++i])
// 	{
// 		i += (num[i] == '+' || num[i] == '-');
// 		if (!ft_isdigit(num[i]))
// 			return (0);
// 	}
// 	return (1);
// }

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
		if (!isnum(nums_strings[i]))
			ft_error_ps(ERR_NON_NUMERIC, argc, nums_strings);
		zeroes += find_zeroes(nums_strings[i]);
	}
	if (zeroes > 1)
		ft_error_ps(ERR_DUPLICATES, argc, nums_strings);
	if (!find_dup(nums_strings))
		ft_error_ps(ERR_DUPLICATES, argc, nums_strings);
	return (nums_strings);
}
