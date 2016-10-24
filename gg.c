/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 10:07:19 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/22 10:08:52 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

static void		set_coord(char *input, t_coord *coord)
{
	int		i;

	i = -1;
	while (++i < 20)
		if (input[i] != '\n' && (input[i] == '#' || (input[i + 1] == '#' &&
			((i + 5 < 19 && input[i + 5] == '#') || (i + 10 < 19 &&
			input[i + 10] == '#'))) || (i + 5 < 19 && input[i + 5] == '#' &&
			(i + 2) % 5 != 0 && input[i + 2] == '#')))
		{
			coord->x = i;
			break ;
		}
	i = 20;
	while (i--)
		if (input[i] != '\n' && (input[i] == '#' || ((i - 1 >= 0 &&
			input[i - 1] == '#') && ((i - 5 >= 0 && input[i - 5] == '#') ||
			(i - 10 >= 0 && input[i - 10] == '#'))) || (i - 5 >= 0 &&
			input[i - 5] == '#' && i % 5 != 0 && input[i - 2] == '#')))
		{
			coord->y = i;
			break ;
		}
	coord->width = coord->y % 5 - coord->x % 5 + 1;
	coord->height = coord->y / 5 - coord->x / 5 + 1;
}

static t_tetri	*set_tetri(char *input, t_coord c, int i)
{
	t_tetri	*t;
	int		j;
	int		k;

	t = (t_tetri*)malloc(sizeof(t_tetri));
	t->a = (char**)malloc((c.height + 1) * sizeof(char*));
	j = -1;
	while (++j < c.height)
		t->a[j] = (char*)malloc((c.width + 1) * sizeof(char));
	j = -1;
	while (++j < c.height)
	{
		k = -1;
		while (++k < c.width)
			t->a[j][k] = input[((c.x / 5 * 5) + (j * 5) + (c.y % 5 - c.width +
																	k + 1))];
		t->a[j][k] = '\0';
	}
	t->a[j] = NULL;
	t->x = c.width;
	t->y = c.height;
	t->letter = 'A' + i;
	return (t);
}

t_tetri			**get_tetri(char *input, int nb_t)
{
	t_coord c;
	t_tetri	**t;
	int		i;

	if ((t = (t_tetri**)malloc((nb_t + 1) * sizeof(t_tetri*))) == NULL)
		return (NULL);
	i = 0;
	while (nb_t--)
	{
		set_coord(input, &c);
		t[i] = set_tetri(input, c, i);
		i++;
		input = input + 21;
	}
	t[i] = NULL;
	return (t);
}
