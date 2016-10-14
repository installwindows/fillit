/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:48:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/06 16:58:48 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri		**tetris;

	if (argc == 2)
	{
		if (!(tetris = validate_input(argv[1])))
			ft_putstr("error\n");
		else
			fillit(tetris);
	}
	else
		ft_putstr("usage: fillit file\n");
	return (0);
}
