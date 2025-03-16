/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:46:00 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/16 17:06:06 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}



void	malloc_fail(int *stack_a, int *stack_b)
{
	if (!stack_a)
	{
		write(STDERR_FILENO, "Malloc fail\n", 13);
	}
	if (!stack_b)
	{
		free(stack_a);
		write(STDERR_FILENO, "Malloc fail\n", 13);
	}
}

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num > 0)
	{
		bits++;
		max_num >>= 1;
	}
	return (bits);
}

int find_min_position(int *stack, int size)
{
    int min_pos = 0;
    int i;
    
    for (i = 1; i < size; i++)
    {
        if (stack[i] < stack[min_pos])
            min_pos = i;
    }
    return min_pos;
}

int find_max_position(int *stack, int size)
{
    int max_pos = 0;
    int i;
    
    for (i = 1; i < size; i++)
    {
        if (stack[i] > stack[max_pos])
            max_pos = i;
    }
    return max_pos;
}

