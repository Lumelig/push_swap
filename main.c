/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:41:08 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/14 14:58:41 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				write(STDERR_FILENO, "Error: Duplicate numbers found!\n", 33);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **input)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (input[i])
	{
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && input[i][j] != '-'
				&& input[i][j] != '+')
			{
				write(STDERR_FILENO,
					"Incorrect input! Only numbers are allowed.\n", 43);
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

void	check_algorithmen(char **input, int size)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = create_stack_a(input, size);
	stack_b = malloc(sizeof(int) * size);
	if (!stack_a || !stack_b)
	{
		malloc_fail(stack_a, stack_b);
		exit(1);
	}
	if (!is_sorted(stack_a, size))
	{
		if (size == 2)
		{
			if (stack_a[0] > stack_a[1])
				rotate_a(stack_a, 2);
		}
		// else if (size == 5)
		// {
		// 	Implement sort_three function for 3 elements
		// 	(Not implemented here but should be for efficiency)
		// }
		else
			radix_sort(stack_a, stack_b, size);
	}
}

int	main(int ac, char **av)
{
	char	**argv;
	int		size;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		argv = ft_split(av[1], ' ');
		size = check_input(argv);
		if (size == 0)
			return (1);
	}
	else
	{
		argv = av + 1;
		size = check_input(argv);
		if (size == 0)
			return (1);
	}
	check_algorithmen(argv, size);
	return (0);
}
