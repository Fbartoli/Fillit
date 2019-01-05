/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:34:10 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 16:57:53 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*static int		check_cell(char cell[5][5], int x, int y)
{
	if (y == 0 && x == 0 && cell[y][x] == '#' && (cell[y][x + 1] == '#'
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
		|| cell[y + 1][x] == '#'|| cell[y][x - 1] == '#'
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
			{	
				i++;
				if (check_cell(piece, x, y) == -1)
					return (-1);
			}
			x++;
		}
		if (x != 4)
			return (-1);
		y++;
	}
	if (i != 4)
		return (-1);
	return (0);
}
*/

int auxf(int x, int y, char cell[5][5])
{
    if (x < 0 || x > 3 || y < 0 || y > 3)
		return (0);
    return (cell[x][y] == '.' ? 0 : 1);
}

int conn(int x, int y, char cell[5][5])
{
	return (auxf(x - 1, y, cell) + auxf(x + 1, y, cell) 
	+ auxf(x, y + 1, cell) + auxf(x, y - 1, cell));
}

static int      check_piece(char piece[5][5])
{
	int n;
	int c;
	int x;
	int y;

	n = 0;
	c = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (piece[x][y] == '.')
				y++;
			else if (piece[x][y] == '#' && conn(x, y, piece) > 0)
			{
				c =  c + conn(x, y, piece);
				n++;
				y++;
			}
			else 
				return (-1);
		}
		x++;
	}
	if (n == 4 && (c == 6 || c == 8))
		return (0);
	return (-1);
}

int		check_tetris(t_etris tetris[27])
{
	int t;
	t = 0;
	while (tetris[t].piece[0][0])
	{
		if (check_piece(tetris[t].piece) == 0)
			t++;
		else
			return (-1);
	}
	if (t > 26)
		return (-1);
	return (0);
}
