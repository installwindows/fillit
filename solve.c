/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:52:13 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/14 04:00:19 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetriminos.h"

static int	does_it_fit(t_square **s, t_tetri *t, int i, int j)
{
	int		x;
	int		y;

	if (i + t->y > (*s)->size || j + t->x > (*s)->size)
		return (0);
	y = 0;
	while (y < t->y)
	{
		x = 0;
		while (x < t->x)
		{
			if (!((*s)->a[i + y][j + x] != '.' && t->a[y][x] == '#'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	place_t(t_square **s, s_tetri *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*s)->size)
	{
		j = 0;
		while (j < (*s)->size)
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
							(*s)->a[i + y][j + x] = t->letter;
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
	(*s)->a = ft_squareplusplus((*s)->a, '.', (*s)->size, (*s)->size + 1);
	return (place_t(s, t));
}


t_square	*solve(t_square *s, t_tetri **t)
{
	while (**t)
	{
		place_t(*t, a);
		t++;
	}
	return (s);
}
