/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:06:27 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/01 19:06:29 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    swap(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second; 
}

//function to swap stack a
void    sa(t_node **stack_a)
{
    swap(stack_a);
	emit_op(OP_SA, "sa");
}

//function to swap stack b
void    sb(t_node **stack_b)
{
    swap(stack_a);
	emit_op(OP_SB, "sb");
}

//function to swap stack a and b
void    ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
	emit_op(OP_SS, "ss");
}
