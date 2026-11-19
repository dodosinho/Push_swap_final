/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:58:38 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/18 12:16:48 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	put_op(char *name, int n, int last)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
	if (last)
		ft_putchar_fd('\n', 2);
	else
		ft_putchar_fd(' ', 2);
}

static void	put_disorder(long inv, long pairs)
{
	long	x;

	x = 0;
	if (pairs > 0)
		x = (inv *20000 + pairs) / (2 * pairs);
	ft_putnbr_fd((int)(x / 100), 2);
	ft_putchar_fd('.', 2);
	if (x % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(x % 100), 2);
}

static void	put_header(long inv, long pairs, char *stategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_disorder(inv, pairs);
	ft_putendl_fd("%", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd(strategy, 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(long inv, long pairs, char *strategy)
{
	int	*c;

	c = op_counts();
	put_header(inv, pairs, strategy);
	ft_putstr_fd("[bench] ", 2);
	put_op("sa", c[OP_SA], 0);
	put_op("sb", c[OP_SB], 0);
	put_op("ss", c[OP_SS], 0);
	put_op("pa", c[OP_PA], 0);
	put_op("pb", c[OP_PB], 01);
	ft_putstr_fd("[bench] ", 2);
	put_op("ra", c[OP_RA], 0);
	put_op("rb", c[OP_RB], 0);
	put_op("rr", c[OP_RR], 0);
	put_op("rra", c[OP_RRA], 0);
	put_op("rrb", c[OP_RRB], 0);
	put_op("rrr", c[OP_RRR], 1);
}
