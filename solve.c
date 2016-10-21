/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:52:13 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/21 08:45:12 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetriminos.h"
#include "libft.h"

t_square	*g_g = NULL;

static void free_t(t_square **s)
{
	int		i;

	i = 0;
	while (i <= (*s)->size)
		free((*s)->a[i++]);
	free(*s);
}

static void	best_best_square(t_square *s, char c)
{
	int		i;
	int		j;
	int		sf;
	int		gf;

	if (c > 'Z')
		return ;
	gf = 0;
	sf  = 0;
	i = 0;
	while (i < s->size)
	{
		j = 0;
		while (j < s->size)
		{
			if (s->a[i][j] == c)
				sf = 1;
			if (g_g->a[i][j] == c)
				gf = 1;
			if (sf && !gf)
			{
				free_t(&g_g);
				g_g = s;
				return ;
			}
			if (gf && !sf)
			{
				free_t(&s);
				return ;
			}
			j++;
		}
		i++;
	}
	best_best_square(s, c + 1);
}

static void	best_square(t_square *s)
{
	int		i;
	int		j;

	if (g_g == NULL)
	{
		g_g = s;
		return ;
	}
	if (s->size < g_g->size)
	{
		free_t(&g_g);
		g_g = s;
		return ;
	}
	else if (s->size == g_g->size)
	{
		i = 0;
		while (i < s->size)
		{
			j = 0;
			while (j < s->size)
			{
				if (s->a[i][j] == '.' && g_g->a[i][j] != '.')
				{
					free_t(&s);
					return ;
				}
				if (g_g->a[i][j] == '.' && s->a[i][j] != '.')
				{
					free_t(&g_g);
					g_g = s;
					return ;
				}
				j++;
			}
			i++;
		}
	}
	best_best_square(s, 'A');
}

static int	does_it_fit(t_square *s, t_tetri *t, int i, int j)
{
	int		x;
	int		y;

	if ((i + t->y > s->size) || (j + t->x > s->size))
		return (0);
	y = 0;
	while (y < t->y)
	{
		x = 0;
		while (x < t->x)
		{
			if (s->a[i + y][j + x] != '.' && t->a[y][x] == '#')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	place_t(t_square *s, t_tetri *t)
{
	int		i;
	int		j;
	int		y;
	int		x;

	i = 0;
	while (i < s->size)
	{
		j = 0;
		while (j < s->size)
		{
			if (does_it_fit(s, t, i, j))
			{
				y = 0;
				while (y < t->y)
				{
					x = 0;
					while (x < t->x)
					{
						if (t->a[y][x] != '.')
							s->a[i + y][j + x] = t->letter;
						x++;
					}
					y++;
				}
				return (1);
			}
			j++;
		}
		i++;
	}
	s->a = ft_squareplusplus(&(s->a), '.', s->size, s->size + 1);
	s->size++;
	return (place_t(s, t));
}

static void swap(t_tetri **t, int i, int j)
{
	t_tetri	*tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

static t_square	*solve(t_tetri **t)
{
	t_square	*s;

	s = (t_square*)malloc(sizeof(t_square));
	s->a = ft_squareplusplus(NULL, '.', 0, 2);
	s->size = 2;
	while (*t)
	{
		place_t(s, *t);
		t++;
	}
	return (s);
}

void	permute(t_tetri **t, int i, int size)
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
