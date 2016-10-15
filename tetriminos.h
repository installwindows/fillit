/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:34:06 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/14 20:59:23 by varnaud          ###   ########.fr       */
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

void	call_me(t_tetri **t, int i, int size);

extern t_square	*g_g;

#endif
