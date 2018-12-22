/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:34:10 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/22 16:47:08 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		check_cell(char **cell, int x, int y)
{
	if (cell[y][x] == '.')
	{
		printf("%c\n", cell[y][x]);
		return (0);
	}
	else if (y == 0 && x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'))
		{
		printf("%c\n", cell[y][x]);
		return (0);
		}
	else if (y == 3 && x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y - 1][x] == '#'))
		{
		printf("%c\n", cell[y][x]);
		return (0);
		}
	else if (y == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#' || cell[y][x - 1] == '#'))
		{
		return (0);
		}
	else if (y == 3 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y - 1][x] == '#'|| cell[x - 1][x] == '#'))
		return (0);
	else if (x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[y - 1][x] == '#'))
		return (0);
	else if (y != 3 && y != 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[x - 1][x] == '#'
		|| cell[y - 1][x] == '#'))
		return (0);
	return (-1);
}

static int		check_tetris(char **tetris)
{
	int x;
	int y;

	y = 0;
	while (tetris[y])
	{
		x = 0;
		while(tetris[y][x])
		{
			if (check_cell(tetris, x, y) == -1)
				return (-1);
			x++;
		}
		if (x != 4)
			return (-1);
		y++;
	}
	return (0);
}

int		check_tab(char ***tab)
{
	int t;
	t = 0;
	while (tab[t])
	{
		if (tab[t] == NULL)
			return (0);
		if (check_tetris(tab[t]) == 0)
			t++;

		else
			return (-1);
	}
	if (t > 25)
		return (-1);
	return (0);
}
