/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:02:21 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/15 06:19:21 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tetriminos.h"
#include "libft.h"

static int		validate_tetri(char *s)
{

}

static char		*read_file(char *argv)
{
	char	*input;
	char	c[21 + 1];
	int		fd;
	int		nb_byte;
	int		i;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((nb_byte = read(fd, c, 21)))
	{
		c[nb_byte] = '\0';
		i = 0;
		while (i < nb_byte)
		{
			if (!(c[i] == '.' || c[i] == '#' || c[i] == '\n'))
				return (NULL);
			i++;
		}
		if (ft_stradd(input, c) == NULL)
			return (NULL);
	}
	close(fd);
	return (input);
}

static void		set_a(char *input, t_tetri *t)
{
	int		i;
	int		y;
	int		x;
	int		first;
	char	*a;

	i = 0;
	y = 0;
	x = 0;
	first = -1;
	while (i < 21 && input[i])
	{
		if (input[i] == '#')
		{
			if ((i + 1) % 5 > x)
				x = (i + 1) % 5;
			if (first == -1)
				first = i;
			else
				y = (i - first) / 5 + 1;
		}
		i++;
	}

}

static t_tetri	**get_tetri(char *input, int nb_t)
{
	t_tetri	**t;
	int		i;

	t = (t_tetri**)malloc((nb_t + 1) * sizeof(t_tetri*));
	t[nb_t] = NULL;
	while (nb_t--)
	{
		t[nb_t] = (t_tetri*)malloc(sizeof(t_tetri));
		i = 0;
		set_a(input, t[nb_t]);
		t[nb_t]->letter = 'A' + nb_t;
		input += 21;
	}
	return (t);
}

t_tetri	**set_tetri(char *file)
{
	int		i;
	int		nb_t;
	char	*input;

	i = 0;
	nb_t = 0;
	if((input = read_file(file)) == NULL)
		return (NULL);
	while (i <= ft_strlen(input))
	{
		if (!validate_tetri(input, i, 21))
			return (NULL);
		nb_t++;
		i += 21;
	}
	return (get_tetri(input, nb_t));
}
