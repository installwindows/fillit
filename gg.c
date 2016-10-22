#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

void	set_coord(char *input, int *x, int *y)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (size < 20)
	{
		if (input[i] != '\n' && (input[i] == '#' || (input[i + 1] == '#' &&
			((i + 5 < 19 && input[i + 5] == '#') || (i + 10 < 19 &&
		 	input[i + 10] == '#'))) || (i + 5 < 19 && input[i + 5] == '#' &&
			(i + 2) % 5 != 0 && input[i + 2] == '#')))
		{
			*x = i;
			break ;
		}
		i++;
		size++;
	}
	size = 0;
	i = 19;
	while (size < 20)
	{
		if (input[i] != '\n' && (input[i] == '#' || ((i - 1 >= 0 &&
			input[i - 1] == '#') && ((i - 5 >= 0 && input[i - 5] == '#') ||
			(i - 10 >= 0 && input[i - 10] == '#'))) || (i - 5 >= 0 &&
			input[i - 5] == '#' && i % 5 != 0 && input[i - 2] == '#')))
		{
			*y = i;
			break ;
		}
		i--;
		size++;
	}
}

t_tetri	**get_tetri(char *input, int nb_t)
{
	int		x;
	int		y;
	t_tetri	**t;
	int		i;

	t = (t_tetri**)malloc((nb_t + 1) * sizeof(t_tetri*));
	i = 0;
	while (nb_t--)
	{
		t[i] = (t_tetri*)malloc(sizeof(t_tetri));
		set_coord(input, &x, &y);
		int		height = y / 5 - x / 5 + 1;
		int		width = y % 5 - x % 5 + 1;
		t[i]->a = (char**)malloc((height + 1) * sizeof(char*));
		int		j = 0;
		while (j < height)
		{
			t[i]->a[j] = (char*)malloc((width + 1) * sizeof(char));
			j++;
		}
		int		k;
		j = 0;
		while (j < height)
		{
			k = 0;
			while (k < width)
			{
				t[i]->a[j][k] = input[((x / 5 * 5) + (j * 5) + (y % 5 - width + k + 1))];
				k++;
			}
			t[i]->a[j][k] = '\0';
			j++;
		}
		t[i]->a[j] = NULL;
		t[i]->x = width;
		t[i]->y = height;
		t[i]->letter = 'A' + i;
		i++;
		input = input + 21;
	}
	t[i] = NULL;
	return (t);
}
/*
int		main(void)
{
	char	*input = "....\n##..\n.#..\n.#..\n\n....\n####\n....\n....\n\n#...\n###.\n....\n....\n\n....\n##..\n.##.\n....\n";
	t_tetri	**t;

	t = get_tetri(input, 4);
	t_tetri	**tmp = t;
	while (*tmp)
	{
		int a = 0;
		printf("%c\n", (*tmp)->letter);
		for (a = 0; a < (*tmp)->y; a++)
			printf("%s\n", ((*tmp)->a)[a]);
		printf("\n");
		tmp++;
	}
	//char	*input = "....\n.##.\n.#..\n.#..\n\n..#.\n.###\n....\n....\n\n....\n##..\n.#..\n.#..\n\n....\n####\n....\n....\n\n#...\n###.\n....\n....\n\n....\n##..\n.##.\n....\n";
	//char	*input = "....\n.##.\n.#..\n.#..\n\n....\n###.\n#...\n....\n";
	//char	*input = "....\n####\n....\n....\n";
	char	*input = "....\n.#..\n.#..\n##..\n";
	int		x;
	int		y;
	char	**a;
	int		i;

	i = 0;
	int		n = 1;
	while (n--)
	{
		a = NULL;
		x = -1;
		y = -1;
		set_coord(input, &x, &y);
		printf("x: %d\ny: %d\n", x, y);
		int		height = y / 5 - x / 5 + 1;
		int		width = y % 5 - x % 5 + 1;
		printf("height: %d\nwidth: %d\n\n", height, width);
		a = (char**)malloc((height + 1) * sizeof(char*));
		int		j = 0;
		while (j < height)
		{
			a[j] = (char*)malloc((width + 1) * sizeof(char));
			j++;
		}
		int		k;
		j = 0;
		while (j < height)
		{
			k = 0;
			while (k < width)
			{
				a[j][k] = input[((x / 5 * 5) + (j * 5) + (y % 5 - width + k + 1))];
				k++;
			}
			a[j][k] = '\0';
			printf("%s\n", a[j]);
			free(a[j]);
			j++;
		}
		//a[j] = NULL;

		i += 21;
		input = input + 21;
	}
}
*/
