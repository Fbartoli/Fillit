/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:34:10 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/27 23:27:05 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		check_cell(char cell[5][5], int x, int y)
{
	printf("x:%d,y:%d \n", x, y);
	if (cell[y][x] == '.')
		return (0);
	else if (y == 0 && x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'))
		return (0);
	else if (y == 3 && x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y - 1][x] == '#'))
		return (0);
	else if (y == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[y - 1][x] == '#'))
		return (0);
	else if (y == 3 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y - 1][x] == '#'|| cell[y][x - 1] == '#'))
		return (0);
	else if (x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[y - 1][x] == '#'))
		return (0);
	else if (x == 3 && cell[y][x] == '#' && (cell[y][x - 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[y - 1][x] == '#'))
		return (0);
	else if (cell[y][x] == '#' && (cell[y][x + 1] == '#'
		|| cell[y + 1][x] == '#'|| cell[x - 1][x] == '#'
		|| cell[y - 1][x] == '#'))
		return (0);
	return (-1);
}

static int		check_piece(char piece[5][5])
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (piece[y][0] != 0)
	{
		x = 0;
		while(piece[y][x] != 0)
		{
			if (piece[y][x] == '#')
				i++;
			if (check_cell(piece, x, y) == -1)
				return (-1);
			x++;
		}
		if (x != 4)
			return (-1);
		printf("\n");
		y++;
	}
	if (i != 4)
		return (-1);
	return (0);
}

int		check_tetris(t_etris tetris[27])
{
	int t;
	t = 0;
	while (tetris[t].piece[0][0])
	{
		printf("\n");
		if (check_piece(tetris[t].piece) == 0)
			t++;
		else
			return (-1);
	}
	if (t > 26)
		return (-1);
	return (0);
}
