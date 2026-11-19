/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:38:27 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/09 14:39:14 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node    *find_min(t_node **stack)
{
    t_node      *min_value;
    t_node      *current_value;

    if (!stack || !*stack)
        return (NULL);
    current_value = *stack;
    min_value = *stack;

    while (current_value != NULL)
    {
        if (current_value->value < min_value->value)
            min_value = current_value;
        current_value = current_value->next;
    }
    return (min_value);
}

int get_position(t_node **stack, t_node *target)
{
    int     i;
    t_node  *current;

    if (!stack || !*stack || !target)
        return (-1);
    i = 0;
    current = *stack;
    while (current != NULL && current != target)
    {
        i++;
        current = current->next;
    }
    if (current == NULL)
        return (-1);
    return (i);
}

int get_total(t_node **stack)
{
    t_node  *current;
    int     i;

    if (!stack || !*stack)
        return (-1);
    current = *stack;
    i = 0;
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return (i);
}

void    sort_simple(t_node **stack_a, t_node **stack_b)
{
    t_node  *min_value;
    int     position;
    int     total;

    if (!stack_a || !*stack_a)
        return ;
    total = get_total(stack_a);
    while (total > 3)
    {
        min_value = find_min(stack_a);
        while (*stack_a != min_value)
        {
            position = get_position(stack_a, min_value);
            if (position == -1)
                return ;
            if (position >= (total / 2))
                rra(stack_a);
            else
                ra(stack_a);
        }    
        pb(stack_a, stack_b);
        total = get_total(stack_a);
    }
}
