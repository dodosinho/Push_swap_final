/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:38:48 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/06 16:45:21 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_radix(t_node **a, t_node **b)
{
	int	size;
	int	bits;
	int	bit;
	int	i;

	size = count_nodes(*a);
	bits = max_bits(*a);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
					ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
