/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putendl_fd.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:34:16 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/13 14:36:31 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
