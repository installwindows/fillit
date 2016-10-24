/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:48:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/22 10:13:56 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include "libft.h"

static void	print_usage(void)
{
	ft_putstr("usage: fillit source_file\n");
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc == 2)
	{
		if (fillit(*++argv) == 1)
		{
			ft_putstr("error\n");
			return (1);
		}
		i = 0;
		while (i < g_g->size)
		{
			ft_putstr(g_g->a[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		print_usage();
	return (0);
}
