/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:56:21 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/02 10:56:24 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	args_ok(int argc, char **argv, int i)
{
	int	j;
	int	found;

	while (i < argc)
	{
		j = 0;
		found = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				found = 1;
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

static char	*join_args(int argc, char **argv, int i)
{
	char	*all;
	char	*temp;

	all = ft_strdup("");
	while (all && i < argc)
	{
		temp =	ft_strjoin(all, argv[i]);
		free (all);
		all = NULL;
		if (temp)
			all = ft_strjoin(temp, " ");
		free (temp);
		i++;
	}
	return (all);
}

static int	fill_tab(char **tokens, int	*tab)
{
	int		i;
	long	n;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			return (0);
		n = ft_atol(tokens[i]);
		if (!in_int_range(n))
			return (0);
		tab[i] = n;
		i++;
	}
	return (!has_duplicate(tab, i));
}

int	*parse_args(int argc, char **argv, int start, int *size)
{
	char	*all;
	char	**tokens;
	int		*tab;

	if (!args_ok(argc, argv, start))
		return (0);
	all = join_args(argc, argv, start);
	if (!all)
		return (0);
	tokens = ft_split(all, ' ');
	free (all);
	if (!tokens)
		return (0);
	*size = 0;
	while (tokens[*size])
		(*size)++;
	tab = malloc(sizeof(int) * (*size));
	if (tab && !fill_tab(tokens, tab))
	{
		free(tab);
		tab = NULL;
	}
	free_split(tokens);
	return (tab);
}
