/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:28 by tanas             #+#    #+#             */
/*   Updated: 2023/04/05 17:06:15 by tanas            ###   ########.fr       */
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
# define ERR_MALLOC_FAIL 4
# define ERR_INVALID_NUM 5

// STRUCTS
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}		t_stack;

// PARSING FUNCTIONS
char	**argv_check(char **argv, int argc);
void	ft_error_ps(int err, int argc, char **nums_strings);
int		check_empty(char *argv);
int		nums_are_sorted(int *numbers, int arr_len);
int		skip_chars(const char *string);

// STACK FUNCTIONS
void	fill_stack_a(t_stack **stack_a, char **nums_strings, int argc);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);

#endif