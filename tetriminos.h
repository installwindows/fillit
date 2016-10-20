/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:34:06 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/20 03:24:24 by varnaud          ###   ########.fr       */
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

enum e_dir
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

extern t_square	*g_g;

void	call_me(t_tetri **t, int i, int size);
t_tetri	**get_tetri(char *file);

#endif
