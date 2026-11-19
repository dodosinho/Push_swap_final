/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:18:12 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/18 12:35:24 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	count_conversions(t_node a)
{
	t_node	*cur;
	long	count;

	count = 0;
	while (a.next != NULL)
	{
		cur = a.next;
		while (cur.value)
		{
			if (a->value > cur->value)
				count++;
			cur = cur.next;
		}
		a = a.next;
	}
	return (count);
}

int	get_disorder(t_node a)
{
	long	n;
	
	n = count_nodes(&a);
	if (n < 2)
		return (0);
	return ((int)(count_inversions(&a) * 100 / (n * (n - 1) / 2)));
}

static t_mode	pick_mode(t_node a)
{
	int	disorder;

	if (count_nodes(&a) <= 3)
		return (SIMPLE);
	disorder = get_disorder(&a);
	if (disorder < 20)
		return (SIMPLE);
	if (disorder < 50)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_stack(t_node **a, t_node **b, t_mode mode)
{
	if (is_sorted(*a))
		return ;
	if (mode == ADAPTIVE)
		mode = pick_mode(*a);
	if (mode == SIMPLE)
		sort_simple(a, b);	
	else if (mode == MEDIUM)
		sort_medium(a, b);
	else 
		sort_radix(a, b);
}

char	*strategy_name(t_mode mode, t_node a)
{
	t_mode	used;

	used = mode;
	if (mode == ADAPTIVE)
		used = pick_mode(a);
	if (mode == ADAPTIVE && used == SIMPLE)
		return ("ADAPTIVE / O(n\302\262)");
	if (mode == ADAPTIVE && used == MEDIUM)
		return ("ADAPTIVE / O(n\342\210\232n)");
	if (mode == ADAPTIVE)
		return ("Adaptive / O(n log n)");
	if (mode == SIMPLE)
		return ("ADAPTIVE / O(n\302\262)");
	if (mode == MEDIUM)
		return ("Medium / O(n\342\210\232n)");
	return ("Complex / O(n log n)");
}
