/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:09:06 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/01 19:09:09 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//rotate function
void    rotate(t_node **stack)
{
    t_node  *first;
    t_node  *second;
    t_node  *current;

    if (!stack || !*stack || !(*stack)->next)
        return ;

    first = *stack;
    second = first->next;
    current = second;
    while(current->next != NULL)
        current = current->next;
    current->next = first;
    first->next = NULL;
    *stack = second;
}

//function to rotate stack a
void    ra(t_node **stack_a)
{
    rotate(stack_a);
	emit_op(OP_RA, "ra");
}

//function to rotate stack b
void    rb(t_node **stack_b)
{
    rotate(stack_b);
	emit_op(OP_RB, "rb");
}

//function to rotate stack a and b
void    rr(t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
	emit_op(OP_SS, "ss");
}
