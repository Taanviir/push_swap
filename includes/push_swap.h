/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:28 by tanas             #+#    #+#             */
/*   Updated: 2023/04/02 16:37:50 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

// COLOUR CODES
# define GREEN "\033[1;32m"
# define RED "\033[1;3;31m"
# define BLUE "\033[3;34m"
# define YELLOW "\033[0;33m"
# define WHITE "\033[0m"

// EXIT CODES
# define ERR_NO_PARAMS 1
# define ERR_NON_NUMERIC 2
# define ERR_DUPLICATES 3

// STRUCTS
typedef struct s_stack
{
	int	value;
}		t_stack;

// FUNCTIONS
void	sa(int *a1, int *a2);
void	sb(int *b1, int *b2);
void	ss(int *a1, int *a2, int *b1, int *b2);
char	**argv_check(char **argv, int argc);
void	ft_error_ps(int err, int argc, char **strings);
int		check_empty(char *argv);

#endif