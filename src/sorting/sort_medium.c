/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:29:56 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/10 15:33:44 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <math.h>

int ft_sqrt(int nb)
{
    int i;

    if (nb <= 0)
        return (0);
    i = 0;
    while (i * i <= nb)
    {
        if (i >= 46340)
            return (i);
        i++;
    }
    return (i - 1);
}

void    find_max(t_node **stack_a, t_node **stack_b, int total)
{
    t_node  *current;
    t_node  *index_max;
    int     position;

    current = *stack_b;
    while (total >= 0)
    {
        while (current != NULL)
        {
            if (current->index == total)
            {
                index_max = current;
                while (index_max != *stack_b)
                {
                    position = get_position(stack_b, index_max);
                    if (position == -1)
                        return ;
                    if (position >= (get_total(stack_b) / 2))
                        rrb(stack_b);
                    else
                        rb(stack_b);
                }
                pa(stack_a, stack_b);
                break ;
            }
            current = current->next;
        }
        total--;
        current = *stack_b;
    }
}

void    medium(t_node **stack_a,t_node **stack_b)
{
    int     total;
    int     chunk;
    int     limit;

    if (!stack_a || !*stack_a)
        return ;
    total = get_total(stack_a);
    chunk = sqrt(total);
    limit = chunk;

    while (get_total(stack_a) > 0)
    {
        if ((*stack_a)->index < limit)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        if (get_total(stack_b) == limit)
            limit += chunk;
    }
    find_max(stack_a, stack_b, total - 1);
}
