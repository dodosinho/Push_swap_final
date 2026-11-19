/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:05:21 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/01 19:05:24 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    pa(t_node **stack_a, t_node **stack_b)
{
    t_node  *top_a;
    t_node  *top_b;
    t_node  *second_b;

    if (!stack_b || !*stack_b)
        return ;
    top_b = *stack_b;
    top_a = *stack_a;
    second_b = top_b->next;
    top_b->next = top_a;
    *stack_b = second_b;
    *stack_a = top_b;
    emit_op(OP_PA, "pa");
}

void    pb(t_node **stack_a, t_node **stack_b)
{
    t_node  *top_a;
    t_node  *top_b;
    t_node  *second_a;

    if (!stack_a || !*stack_a)
        return ;
    top_b = *stack_b;
    top_a = *stack_a;
    second_a = top_a->next;
    top_a->next = top_b;
    *stack_a = second_a;
    *stack_b = top_a;
	emit_op(OP_PB, "pb");
}
