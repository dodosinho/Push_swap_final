/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:19:05 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/10 15:19:41 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    get_index(t_node **stack_a)
{
    t_node  *current;
    t_node  *compaire;
    int     i;

    current = *stack_a;
    i = 0;
    while (current != NULL)
    {
        i = 0;
        compaire = *stack_a;
        while (compaire != NULL)
        {
            if (current->value > compaire->value)
                i++;
            compaire = compaire->next;
        }
        current->index = i;
        current = current->next;
    }
}
