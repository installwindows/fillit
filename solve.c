/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:52:13 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/22 12:54:16 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetriminos.h"
#include "libft.h"

t_square	*g_g = NULL;

static int		free_t(t_square *s)
{
	int		i;

	i = 0;
	while (i < s->size)
		free(s->a[i++]);
	free(s->a);
	free(s);
	return (0);
}

static int		best_best_square(t_square *s, char c)
{
	int		i;
	int		j;
	int		sf;
	int		gf;

	if (c > 'Z')
		return (0);
	gf = 0;
	sf = 0;
	i = -1;
	while (++i < s->size && (j = -1))
		while (++j < s->size)
		{
			sf = s->a[i][j] == c ? 1 : 0;
			gf = g_g->a[i][j] == c ? 1 : 0;
			if (sf && !gf)
			{
				free_t(g_g);
				g_g = s;
				return (0);
			}
			if (gf && !sf)
				return (free_t(s));
		}
	return (best_best_square(s, c + 1));
}

static void		best_square(t_square *s)
{
	int		nb_dots;

	nb_dots = 0;
	if (g_g == NULL)
		g_g = s;
	else if (s->nb_dots < g_g->nb_dots)
	{
		free_t(g_g);
		g_g = s;
	}
	else if (s->nb_dots == g_g->nb_dots)
		best_best_square(s, 'A');
	else
		free_t(s);
}

static void		swap(t_tetri **t, int i, int j)
{
	t_tetri	*tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

void			permute(t_tetri **t, int i, int size)
{
	int		j;

	if (i == size)
		best_square(solve(t));
	else
	{
		j = i;
		while (j <= size)
		{
			swap(t, i, j);
			permute(t, i + 1, size);
			swap(t, i, j);
			j++;
		}
	}
}
