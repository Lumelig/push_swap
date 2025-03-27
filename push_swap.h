/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:45:31 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/27 20:33:16 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>

int	find_max_index(int *stack, int size);
/* Input Validation */
int		check_valid_input(char **input);
int		has_duplicates(int *arr, int size);
int		is_sorted(int *stack, int size);

/* Stack Initialization */
int		*create_stack_a(char **input, int size);
void	malloc_fail(int *stack_a, int *stack_b);

/* Sorting Algorithms */
void	hard_sort(int *stack_a, int *stack_b, int size);
void	radix_sort(int max_bits, int size, int *stack_a, int *stack_b);
void	sort_small(int *stack_a, int *stack_b, int size);
void	sort_3(int *stack_a, int size_a);
void	easy_sort(int *stack_a, int *stack_b, int size);
void	sort_by_chunks(int *stack_a, int *stack_b, int size);

/* Indexing & Sorting Helpers */
void	decision_maker1(char **input, int size);
void	index_stack(int *stack_a, int size);
void	index_sort(int *copy, int size);
void	create_index(int *stack_a, int *copy, int size, int *index);
int		get_max_bits(int max_num);
void	process_chunk(int *stack_a, int *stack_b, int size, int *current_vals);
void	push_max_from_b(int *stack_a, int *stack_b, int *size_a, int *size_b);

/* Stack Operations */
void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	swap_a(int *stack_a, int size_a);
void	swap_b(int *stack_b, int size_b);
void	swap_both(int *stack_a, int *stack_b, int size_a, int size_b);
void	rotate_a(int *stack_a, int size_a);
void	rotate_b(int *stack_b, int size_b);
void	rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);
void	reverse_rotate_a(int *stack_a, int size_a);
void	reverse_rotate_b(int *stack_b, int size_b);
void	reverse_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);

/* Utility Functions */
void	error_return(void);
int		find_max_position(int *stack, int size);
int		find_min_position(int *stack, int size);

#endif
