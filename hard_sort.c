/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:32:38 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/16 22:33:06 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_from_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	j;
	int	max_val;
	int	max_pos;

	max_val = -1;
	max_pos = 0;
	j = -1;
	while (++j < *size_b)
	{
		if (stack_b[j] > max_val)
		{
			max_val = stack_b[j];
			max_pos = j;
		}
	}
	j = 0;
	if (max_pos <= *size_b / 2)
		while (j++ < max_pos)
			rotate_b(stack_b, *size_b);
	else
		while (j++ < *size_b - max_pos)
			reverse_rotate_b(stack_b, *size_b);
	push_a(stack_a, stack_b, size_a, size_b);
}

void	process_chunk(int *stack_a, int *stack_b, int size, int *current_vals)
{
	int	i;
	int	size_a;
	int	size_b;
	int	chunk_min;
	int	chunk_max;

	size_a = current_vals[0];
	size_b = current_vals[1];
	chunk_min = current_vals[2];
	chunk_max = current_vals[3];
	i = 0;
	while (i < size && size_a > 0)
	{
		if (stack_a[0] >= chunk_min && stack_a[0] <= chunk_max)
			push_b(stack_a, stack_b, &size_a, &size_b);
		else
			rotate_a(stack_a, size_a);
		i++;
	}
	while (size_b > 0)
		push_max_from_b(stack_a, stack_b, &size_a, &size_b);
	current_vals[0] = size_a;
	current_vals[1] = size_b;
}

void	sort_by_chunks(int *stack_a, int *stack_b, int size)
{
	int	current_vals[4];
	int	num_chunks;
	int	chunk_size;
	int	current_max;

	current_vals[0] = size;
	current_vals[1] = 0;
	num_chunks = 5;
	chunk_size = size / num_chunks;
	current_max = size - 1;
	while (current_max >= 0)
	{
		current_vals[2] = current_max - chunk_size + 1;
		if (current_vals[2] < 0)
			current_vals[2] = 0;
		current_vals[3] = current_max;
		process_chunk(stack_a, stack_b, size, current_vals);
		current_max -= chunk_size;
	}
}

void	radix_sort(int max_bits, int size, int *stack_a, int *stack_b)
{
	int	size_b;
	int	size_a;
	int	i;
	int	j;

	size_a = size;
	size_b = 0;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (size_a > 0)
			{
				if ((stack_a[0] >> i) & 1)
					rotate_a(stack_a, size_a);
				else
					push_b(stack_a, stack_b, &size_a, &size_b);
			}
		}
		while (size_b > 0)
			push_a(stack_a, stack_b, &size_a, &size_b);
	}
}

void	hard_sort(int *stack_a, int *stack_b, int size)
{
	int	max_bits;

	max_bits = get_max_bits(size - 1);
	index_stack(stack_a, size);
	if (size <= 1)
		sort_by_chunks(stack_a, stack_b, size);
	else
		radix_sort(max_bits, size, stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}
