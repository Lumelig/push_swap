/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:41:08 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/06 15:28:32 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *create_stack_a(char **input, int size)
{
    int    *stack_a;
    int i;
    int j;
    

    i = 0;
    j = 0;
    stack_a = malloc(sizeof(int) * size);
    if (!stack_a)
    {
        write(STDERR_FILENO, "Malloc fail\n", 13);
        return (NULL);
    }
    stack_a[size] = '\0';
    while (i < size)
    {
        stack_a[i] = ft_atoi(input[i]);
        printf("%i\n", stack_a[i]);
        i++;
    }
    return (stack_a);
}

int check_input(char **input)
{
    int j = 0;
    int i = 0;

    while (input[i])
    {
        while (input[i][j])
        {
            if (!ft_isdigit(input[i][j]) && input[i][j] != '-')
            {
                write(STDERR_FILENO, "Incorrect input! Only numbers are allowed.\n", 43);
                return (0);
            }
            j++;
        }
        i++;
        j = 0; 
    }
    return (++i);
}

int main(int ac, char **av)
{
    char    **argv;
    int    *stack_a;
    int size;
    
    if (ac == 1)
        return (0);
    else if (ac == 2)
    {
        argv = ft_split(av[1], ' ');
        size = check_input(argv);
    }
    else
    {
        argv = av + 1;
        size = check_input(argv);
    }
    stack_a = create_stack_a(argv, size);
    return 0;
}
