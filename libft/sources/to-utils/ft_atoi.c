/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:23:32 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 17:39:21 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	pos;
	int	num;

	pos = 0;
	num = 0;
	sign = 1;
	while (str[pos] && (str[pos] == '\n' || str[pos] == ' ' || str[pos] == '\t' \
			|| str[pos] == '\r' || str[pos] == '\v' || str[pos] == '\f'))
		pos++;
	if (str[pos] == '-')
		sign = -1;
	pos = (str[pos] == '+' || str[pos] == '-');
	while (str[pos] >= '0' && str[pos] <= '9')
		num = num * 10 + (str[pos++] - 48);
	return (num * sign);
}
