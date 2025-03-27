/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:04:20 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/27 20:32:49 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_return(void)
{
	write(2, "Error\n", 6);
	exit(1);
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

void	index_stack(int *stack_a, int size)
{
	int	*copy;
	int	*index;
	int	i;

	copy = malloc(sizeof(int) * size);
	index = malloc(sizeof(int) * size);
	if (!copy || !index)
	{
		if (copy) free(copy);
	if (index) free(index);

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
