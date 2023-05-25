/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:28 by tanas             #+#    #+#             */
/*   Updated: 2023/05/25 13:51:21 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include "libft.h"
# include <stdio.h>

// EXIT CODES
# define ERR_NO_PARAMS 1
# define ERR_NON_NUMERIC 2
# define ERR_DUPLICATES 3
# define ERR_MALLOC_FAIL 4
# define ERR_INVALID_NUM 5
# define ERR_EMPTY_ARG 6

// STRUCTS
typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

// ERROR CHECK FUNCTIONS
char	**argv_check(char **argv, int argc);
int		check_empty(char *argv);
char	**join_args(char **argv, int argc);
void	close_prog(int err, char **strings, void *arr, t_stack **stack);

// STACK FUNCTIONS
void	fill_stack_a(t_stack **stack_a, char **validated_args, int stack_size);
int		get_arr_size(char **args);
int		get_stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

// STACK OPERATIONS
void	free_stack(t_stack **stack, int stack_size);
void	swap_ops(t_stack **stack_a, t_stack **stack_b, char c);
void	push_ops(t_stack **stack_a, t_stack **stack_b, char c);
void	rotate_stack(t_stack **stack_a, t_stack **stack_b, char c);
void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b, char c);

// SORT FUNCTIONS
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	quicksort(int *numbers, int start, int end);

#endif