/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:48:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/22 09:16:32 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tetriminos.h"
#include "libft.h"

void	testing()
{
	char	*t1[] = {"##", ".#", ".#"};
	char	*t2[] = {"####"};
	char	*t3[] = {"#..", "###"};
	char	*t4[] = {"##.", ".##"};
	t_tetri	**t;
	int		n;
	char	c;

	n = 4;
	c = 'A' + n;
	t = (t_tetri**)malloc((n + 1) * sizeof(t_tetri*));
	t[n] = NULL;
	while (n--)
	{
		t[n] = (t_tetri*)malloc(sizeof(t_tetri));
		t[n]->letter = --c;
	}
	t[0]->y = 3;
	t[0]->x = 2;
	t[0]->a = t1;
	t[1]->y = 1;
	t[1]->x = 4;
	t[1]->a = t2;
	t[2]->y = 2;
	t[2]->x = 3;
	t[2]->a = t3;
	t[3]->y = 2;
	t[3]->x = 3;
	t[3]->a = t4;
	t_square 	*square;

	square = (t_square*)malloc(sizeof(t_square));
	square->size = 4;
	square->a = ft_squareplusplus(NULL, '.', 0, 4);

	t_tetri	**tmp = t;
	while (*tmp)
	{
		int a = 0;
		printf("%c\n", (*tmp)->letter);
		for (a = 0; a < (*tmp)->y; a++)
			printf("%s\n", ((*tmp)->a)[a]);
		printf("\n");
		tmp++;
	}

	permute(t, 0, 4 - 1);
	printf("\nGG?\n");
	int		i;
	if (g_g)
		for (i = 0; i < g_g->size; i++)
			printf("%s\n", g_g->a[i]);
	else
		printf(":(\n");
}

void	print_usage()
{
	ft_putstr("usage: fillit source_file\n");
}

int		main(int argc, char **argv)
{
	//testing();
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
	{
		print_usage();
	}
	return (0);
}
