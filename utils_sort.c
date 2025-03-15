/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:58:27 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/15 13:58:40 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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