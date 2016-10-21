/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:02:21 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/21 07:50:21 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetriminos.h"
#include "libft.h"

static void		flood_fill(char *s, int size, int i)
{
	if (i > size || i < 0)
		return ;
	if (s[i] != '#')
		return ;
	s[i] = '1';
	flood_fill(s, size, i - 5);
	flood_fill(s, size, i + 5);
	flood_fill(s, size, i - 1);
	flood_fill(s, size, i + 1);
}

static int		validate_tetri(char *s, int size, int i)
{
	int		j;
	int		flooded;

	flooded = 1;
	j = 0;
	while (j < 20)
	{
		if (((j + 1) % 5 == 0 && s[j] != '\n') || (s[j] == '\n' &&
					(j + 1) % 5 != 0))
			return (0);
		if (flooded && s[j] == '#')
		{
			flood_fill(s, ft_strlen(s), j);
			flooded = 0;
		}
		else if (s[j] == '#')
			return (0);
		j++;
	}
	if (j + i < size && s[j] != '\n')
		return (0);
	j = 0;
	while (j < 20)
	{
		if (s[j] == '1')
		{
			s[j] = '#';
			flooded++;
		}
		j++;
	}
	if (flooded != 4)
		return (0);
	return (1);
}

static char		*read_file(char *argv)
{
	char	*input;
	char	c[21 + 1];
	int		fd;
	int		nb_byte;
	int		i;

	input = NULL;
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
		if (ft_stradd(&input, c) == NULL)
			return (NULL);
	}
	close(fd);
	return (input);
}

int				fillit(char *file)
{
	int		i;
	int		nb_t;
	char	*input;

	i = 0;
	nb_t = 0;
	if((input = read_file(file)) == NULL)
		return (1);
	while (input[i] != '#')
		i++;
	i = 0;
	while (i <= ft_strlen(input))
	{
		if (!validate_tetri(input + i, ft_strlen(input), i))
			return (1);
		nb_t++;
		i += 21;
	}
	ft_putstr(input);
	//call get_blocks
	//call permutation
	return (0);
}
