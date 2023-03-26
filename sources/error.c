/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:09 by tanas             #+#    #+#             */
/*   Updated: 2023/03/26 17:16:52 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for numbers only. 0 returned if non-digit char found
static int	isnum(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]))
			return (0);
	return (1);
}

// comparing numbers and checking for duplicates
static int	ft_nbrcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i += (s1[i] == '+');
	j += (s2[j] == '+');
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

	i = 0;
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

void	multi_argv_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!isnum(argv[i]))
			ft_error("Error.", ERR_NON_NUMERIC);
	}
	if (!find_dup(argv))
		ft_error("Error.", ERR_DUPLICATES);
}

void	single_argv_check(char *nums)
{
	int	i;

	i = -1;
	while (nums[++i])
	{
		if (nums[i] == ' ')
			i++;
		if (!ft_isdigit(nums[i]))
			ft_error("Error.", ERR_NON_NUMERIC);
	}
	// if (!find_dup(&nums))
	// 	ft_error("Error.", ERR_DUPLICATES);
}