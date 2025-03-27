/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:32:38 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/27 20:34:10 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	radix_sort(max_bits, size, stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}
