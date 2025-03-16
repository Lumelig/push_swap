/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:35 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/16 19:10:39 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	temp_a;
	int	temp_b;

	if (size_a >= 2 && size_b >= 2)
	{
		temp_a = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp_a;
		temp_b = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp_b;
		write(STDOUT_FILENO, "ss\n", 3);
	}
}

void	rotate_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	temp_a;
	int	temp_b;

	if (size_a >= 2 && size_b >= 2)
	{
		i = 0;
		temp_a = stack_a[0];
		while (i < size_a - 1)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[size_a - 1] = temp_a;
		temp_b = stack_b[0];
		i = 0;
		while (i < size_b - 1)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[size_b - 1] = temp_b;
		write(STDOUT_FILENO, "rr\n", 3);
	}
}

void	reverse_rotate_a(int *stack_a, int size_a)
{
	int	temp;
	int	i;

	if (size_a < 2)
		return ;
	temp = stack_a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(int *stack_b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return ;
	temp = stack_b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i++;
	}
	stack_b[0] = temp;
	write(STDOUT_FILENO, "rrb\n", 4);
}
