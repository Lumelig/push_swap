/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:36:34 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/11 13:37:19 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int i;
    
    if (*size_b == 0)
        return;
    i = *size_a;
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = stack_b[0];
    (*size_a)++;
    i = 0;
    while (i < *size_b - 1)
    {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    
    (*size_b)--;
    write(1, "pa\n", 3);
}

void push_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int i;
    
    if (*size_a == 0)
        return;
    i = *size_b;
    while (i > 0)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[0] = stack_a[0];
    (*size_b)++;
    i = 0;
    while (i < *size_a - 1)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    
    (*size_a)--;
    write(1, "pb\n", 3);
}

void rotate_a(int *stack_a, int size_a)
{
    int temp;
    int i;
    
    if (size_a <= 1)
        return;
    
    temp = stack_a[0];
    
    i = 0;
    while (i < size_a - 1)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    
    stack_a[size_a - 1] = temp;
    write(1, "ra\n", 3);
}