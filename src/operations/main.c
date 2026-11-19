/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:00:17 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/06 16:54:51 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	load_stack(int ac, char **av, int start, t_node **a)
{
	int	*tab;
	int	size;

	tab = parse_args(ac, av, start, &size);
	if (!tab)
		return (0);
	if (!stack_init(a, tab, size))
	{
		free(tab);
		free_stack(a);
		return (0);
	}
	free(tab);
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_mode	mode;
	int		bench;
	int		start;

	a = NULL;
	b = NULL;
	start = parse_flags(ac, av, &mode, &bench);
	if (start == -1)
		return (print_error());
	if (start >= ac)
		return (0);
	if (!load_stack(ac, av, start, &a))
		return (print_error());
	get_index(&a);
	run_sort(&a, &b, mpde, bench);
	free_stacks(&a, &b);
	return (0);
}
