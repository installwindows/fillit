/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:02:21 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/07 01:00:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tetriminos.h"
#include "libft.h"

static t_tetri	*validate_tetriminos(char *s)
{

}

static char		*read_file(char *argv)
{
	char	*input;
	char	c[21 + 1];
	int		fd;
	int		nb_byte;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((nb_byte = read(fd, c, 21)))
	{
		c[nb_byte] = '\0';
		if (!(c[0] == '.' || c[0] == '#' || c == '\n'))
			return (NULL);
		if (ft_stradd(input, c) == NULL)
			return (NULL);
	}
	close(fd);
	return (input);
}

t_tetriminos	**validate_file(char *argv)
{
	int		i;
	int		nb_tetri;
	char	*input;
	t_tetri	tetri;

	i = 0;
	nb_tetri = 1;
	if((input = read_file(argv)) == NULL)
		return (NULL);
	while (input[i])
	{
		tetri.
		i++;
	}
}
