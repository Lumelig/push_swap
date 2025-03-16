/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:41:08 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/16 17:14:37 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *arr, int size)
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
				write(2, "Error: Duplicate numbers found!\n", 33);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
	if (check_duplicates(stack_a, size))
	{
		free(stack_a);
		exit(1);
	}
	return (stack_a);
}
int	check_valid_input(char **input)
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
				write(2,
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

void	decision_maker1(char **input, int size)
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
		else if (size <= 5)
		{
			easy_sort(stack_a, stack_b, size);
		}
		else
			hard_sort(stack_a, stack_b, size);
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
		if (!argv[1])
		{
			write(2,"How to sort one number ??? try again\n", 38);
		}
		argv = ft_split(av[1], ' ');
		size = check_valid_input(argv);
		if (size == 0)
			return (1);
	}
	else
	{
		argv = av + 1;
		size = check_valid_input(argv);
		if (size == 0)
			return (1);
	}
	decision_maker1(argv, size);
	return (0);
}

// from random import randint
// from sys import argv
// if __name__ == "__main__":
// 	elem = []
// 	for i in range(int(argv[1])):
// 		buffer = randint(int(argv[2]), int(argv[3]))
// 		while buffer in elem:
// 			buffer = randint(int(argv[2]), int(argv[3]))
// 		elem.append(buffer)
// 	s = '"'
// 	for i in elem:
// 		s += str(i) + ' '
// 	s += '"'
// 	print(s)


//https://github.com/gemartin99/Push-Swap-Tester