/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:52:13 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/14 21:20:35 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetriminos.h"
#include "libft.h"

#include <stdio.h>
t_square	*g_g = NULL;

static void free_t(t_square **s)
{
	int		i;

	i = 0;
	while (i <= (*s)->size)
		free((*s)->a[i++]);
	free(*s);
}

static void	best_square(t_square *s)
{
	int		i;
	int		j;

	if (g_g == NULL)
	{
		g_g = s;
		printf("g_g's not null\n");
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
	free_t(&s);
}

static int	does_it_fit(t_square *s, t_tetri *t, int i, int j)
{
	int		x;
	int		y;
	//printf("Hello\n");
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

void	call_me(t_tetri **t, int i, int size)
{
	int		j;

	if (i == size)
	{
		//printf("ayyyyyyyyy\n");
		best_square(solve(t));
	}
	else
	{
		j = i;
		while (j <= size)
		{
			swap(t, i, j);
			call_me(t, i + 1, size);
			swap(t, i, j);
			j++;
		}
	}
}
