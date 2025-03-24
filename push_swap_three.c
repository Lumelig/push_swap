/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:45:24 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/23 16:37:00 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	temp_a;
	int	temp_b;

	i = size_a - 1;
	if (size_a >= 2 && size_b >= 2)
	{
		temp_a = stack_a[size_a - 1];
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[0] = temp_a;
		temp_b = stack_b[size_b - 1];
		i = size_b - 1;
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[0] = temp_b;
		write(1, "rrr\n", 4);
	}
}

void	swap_b(int *stack_b, int size_b)
{
	int	temp;

	if (size_b < 2)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "sb\n", 3);
}
