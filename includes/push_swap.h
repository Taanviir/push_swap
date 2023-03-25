/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:28 by tanas             #+#    #+#             */
/*   Updated: 2023/03/25 16:58:16 by tanas            ###   ########.fr       */
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

// STRUCTS
typedef struct s_stack
{
	int	value;
}		t_stack;

// FUNCTIONS
void	sa(int *a1, int *a2);
void	sb(int *b1, int *b2);
void	ss(int *a1, int *a2, int *b1, int *b2);
void	error_check(char **argv);

#endif