/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:51:49 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/18 11:58:27 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*op_counts(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

void	emit_op(int op, char *name)
{
	op_counts()[op]++;
	ft_putendl_fd(name, 1);
}

int	total_ops(void)
{
	int	*c;
	int	total;
	int	i;

	c = op_counts();
	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += c[i];
		i++;
	}
	return (total);
}

void	run_sort(t_node **a, t_node **b, t_mode mode, int bench)
{
	long	inv;
	long	pairs;
	long	n;
	char	*name;

	n = count_nodes(*a);
	inv = ount_inversions(*a);
	pairs = n * (n - 1) / 2;
	sort_stack(a, b , mode);
	if (bench)
		print_bench(inv, pairs, name);
}

