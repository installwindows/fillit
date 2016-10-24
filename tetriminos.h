/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:34:06 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/22 12:10:41 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

typedef struct	s_tetri
{
	char		**a;
	int			y;
	int			x;
	char		letter;
}				t_tetri;

typedef struct	s_square
{
	char		**a;
	int			size;
	int			nb_dots;
}				t_square;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_coord;

extern t_square	*g_g;

t_tetri			**get_tetri(char *input, int nb_t);
t_square		*solve(t_tetri **t);
void			permute(t_tetri **t, int i, int size);
int				fillit(char *file);

#endif
