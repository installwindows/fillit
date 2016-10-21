/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 09:54:27 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/21 09:54:37 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetriminos.h"
#include "libft.h"

static int		does_it_fit(t_square *s, t_tetri *t, int i, int j)
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

static void		insert_t(t_square *s, t_tetri *t, int i, int j)
{
	int		y;
	int		x;

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
}

static int		place_t(t_square *s, t_tetri *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->size)
	{
		j = 0;
		while (j < s->size)
		{
			if (does_it_fit(s, t, i, j))
			{
				insert_t(s, t, i, j);
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

t_square		*solve(t_tetri **t)
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
