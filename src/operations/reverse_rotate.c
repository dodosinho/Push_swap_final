/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:09:39 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/01 19:09:42 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//rrotate function
void    rrotate(t_node **stack)
{
    t_node  *first;
    t_node  *before_end;
    t_node  *end;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    before_end = first;
    while (before_end->next->next != NULL)
        before_end = before_end->next;
    end = before_end->next;
    end->next = first;
    before_end->next = NULL;
    *stack = end;
}

//rrotate function stack a
void    rra(t_node **stack_a)
{
    rrotate(stack_a);
	emit_op(OP_RRA, "rra");
}

//rrotate function stack b
void    rrb(t_node **stack_b)
{
    rrotate(stack_b);
	emit_op(OP_RRB, "rrb");
}

//rrotate function stack a and b
void    rrr(t_node **stack_a, t_node **stack_b)
{
    rrotate(stack_a);
    rrotate(stack_b);
	emit_op(OP_RRR, "rrr");
}
