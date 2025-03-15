/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:45:31 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/15 14:44:20 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

int		check_input(char **input);

int		*create_stack_a(char **input, int size);

int		has_duplicates(int *arr, int size);

int		is_sorted(int *stack, int size);

void	malloc_fail(int *stack_a, int *stack_b);

void	radix_sort(int *stack_a, int *stack_b, int size);

void	*sort_by_bit(int max_bits, int size, int *stack_a, int *stack_b);

void	rotate_a(int *stack_a, int size_a);

void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	create_index(int *stack_a, int *copy, int size, int *index);

void	index_sort(int *copy, int size);

int		get_max_bits(int max_num);

void	index_stack(int *stack_a, int size);

void sort_small(int *stack_a, int *stack_b, int size);

void sort_3(int *stack_a, int size_a);

int find_max_position(int *stack, int size);

int find_min_position(int *stack, int size);

void reverse_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);

void reverse_rotate_b(int *stack_b, int size_b);

void reverse_rotate_a(int *stack_a, int size_a);

void rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);

void swap_both(int *stack_a, int *stack_b, int size_a, int size_b);

void bubble_sort(int *stack_a, int *stack_b, int size);

void swap_b(int *stack_b, int size_b);

void swap_a(int *stack_a, int size_a);

void	rotate_a(int *stack_a, int size_a);

#endif