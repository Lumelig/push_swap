/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:46:00 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/14 14:51:54 by jpflegha         ###   ########.fr       */
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

int	*create_stack_a(char **input, int size)
{
	int	*stack_a;
	int	i;

	stack_a = malloc(sizeof(int) * size);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack_a[i] = ft_atoi(input[i]);
		i++;
	}
	if (has_duplicates(stack_a, size))
	{
		free(stack_a);
		exit(1);
	}
	return (stack_a);
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
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
