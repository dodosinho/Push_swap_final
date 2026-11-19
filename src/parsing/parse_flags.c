/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:57:07 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/18 12:21:45 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_mode(char *arg)
{
	if(!ft_strncmp(arg, "--simple", 9))
		return (SIMPLE);
	if (!ft_strncmp(arg, "--medium", 9))
		return (MEDIUM);
	if(!ft_strncmp(arg, "--complex", 10))
		return (COMPLEX);
	if(!ft_strncmp(arg, "--adaptive", 11))
		return (ADAPTIVE);
	return (-1);
}

int	parse_flags(int argc, char **argv, t_mode *mode, int *bench)
{
	int	i;
	int	m;
	int	found;

	i = 1;
	found = 0;
	*mode = ADAPTIVE;
	*bench = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 8) && !*bench)
			*bench = 1;
		else
		{
			m = get_mode(argv[i]);
			if (m == -1 || found)
				return (-1);
			*mode = m;
			found = 1;
		}
		i++;
	}
	return (i);
}
