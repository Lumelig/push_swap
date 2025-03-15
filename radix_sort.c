/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:32:38 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/15 19:02:02 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(int *stack_a, int size)
{
	int	*copy;
	int	*index;
	int	i;
	int	j;
	int	temp;

	copy = malloc(sizeof(int) * size);
	index = malloc(sizeof(int) * size);
	if (!copy || !index)
	{
		if (copy)
			free(copy);
		else if (index)
			free(index);
		return ;
	}
	i = 0;
	while (i < size)
	{
		copy[i] = stack_a[i];
		i++;
	}
	index_sort(copy, size);
	create_index(stack_a, copy, size, index);
}

void	index_sort(int *copy, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (copy[j] > copy[j + 1])
			{
				temp = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	create_index(int *stack_a, int *copy, int size, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (stack_a[i] == copy[j])
			{
				index[i] = j;
				break ;
			}
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		stack_a[i] = index[i];
		i++;
	}
	free(copy);
	free(index);
}

void	sort_by_bit(int max_bits, int size, int *stack_a, int *stack_b)
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
				if (((stack_a[0] >> i) & 1) & 1)
					rotate_a(stack_a, size_a);
				else
					push_b(stack_a, stack_b, &size_a, &size_b);
			}
		}
		while (size_b > 0)
			push_a(stack_a, stack_b, &size_a, &size_b);
	}
}

void	radix_sort(int *stack_a, int *stack_b, int size)
{
	int	max_bits;

	if (!is_sorted(stack_a, size) || size <= 1)
	{
		index_stack(stack_a, size);
		max_bits = get_max_bits(size - 1);
		sort_by_bit(max_bits, size, stack_a, stack_b);
	}
	free(stack_a);
	free(stack_b);
}
