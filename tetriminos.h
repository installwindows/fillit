/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:34:06 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/21 17:09:15 by varnaud          ###   ########.fr       */
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
}				t_square;

extern t_square	*g_g;

t_tetri			**get_tetri(char *input, int nb_t);
t_square		*solve(t_tetri **t);
void			permute(t_tetri **t, int i, int size);
int				fillit(char *file);

#endif
