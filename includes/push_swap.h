/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:28 by tanas             #+#    #+#             */
/*   Updated: 2023/05/01 16:05:21 by tanas            ###   ########.fr       */
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
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

// ERROR CHECK FUNCTIONS
char	**argv_check(char **argv, int argc);
void	ft_error_ps(int err, char **nums_strings);
int		check_empty(char *argv);
int		nums_are_sorted(int *numbers, int arr_len);
int		skip_chars(const char *string);
char	**join_args(char **argv, int argc);

// PARSE FUNCTIONS
void	fill_stack_a(t_stack **stack_a, int *numbers, int arr_len);
int		*get_numbers(char **num_strings, int arr_len);
int		get_stack_size(char **args);

// SORT FUNCTIONS
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// STACK OPERATIONS
void	free_stack(t_stack **stack, int stack_size);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack(t_stack **stack_a, t_stack **stack_b, char c);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b, char c);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void print_list(t_stack *head);

#endif