/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:57 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/15 14:41:30 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(int *stack_a, int size_a)
{
    int max_pos;
    
    if (size_a < 3)
        return;
    
    max_pos = find_max_position(stack_a, 3);
    
    if (max_pos == 0)
    {
        rotate_a(stack_a, size_a);
        if (stack_a[0] > stack_a[1])
            swap_a(stack_a, size_a);
    }
    else if (max_pos == 1)
    {
        reverse_rotate_a(stack_a, size_a);
        if (stack_a[0] > stack_a[1])
            swap_a(stack_a, size_a);
    }
    else
    {
        if (stack_a[0] > stack_a[1])
            swap_a(stack_a, size_a);
    }
}

void sort_small(int *stack_a, int *stack_b, int size)
{
    int size_a = size;
    int size_b = 0;
    int min_pos;
    
    while (size_a > 3)
    {
        min_pos = find_min_position(stack_a, size_a);
        if (min_pos == 0)
            push_b(stack_a, stack_b, &size_a, &size_b);
        else if (min_pos <= size_a / 2)
        {
            while (min_pos-- > 0)
                rotate_a(stack_a, size_a);
            push_b(stack_a, stack_b, &size_a, &size_b);
        }
        else
        {
            while (min_pos++ < size_a)
                reverse_rotate_a(stack_a, size_a);
            push_b(stack_a, stack_b, &size_a, &size_b);
        }
    }
    sort_3(stack_a, size_a);
    while (size_b > 0)
        push_a(stack_a, stack_b, &size_a, &size_b);
}

void bubble_sort(int *stack_a, int *stack_b, int size)
{
    if(!is_sorted(stack_a, size))
    {
        if (size == 3)
        {
            sort_3(stack_a, size);
        }
        else
            sort_small(stack_a, stack_b, size);
    }
    free(stack_a);
	free(stack_b);
}