/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:34:10 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 18:51:33 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		auxf(int x, int y, char cell[5][5])
{
	if (x < 0 || x > 3 || y < 0 || y > 3)
		return (0);
	return (cell[x][y] == '.' ? 0 : 1);
}

static int		conn(int x, int y, char cell[5][5])
{
	return (auxf(x - 1, y, cell) + auxf(x + 1, y, cell)
	+ auxf(x, y + 1, cell) + auxf(x, y - 1, cell));
}

static int		check_piece(char piece[5][5])
{
	int n;
	int c;
	int x;
	int y;

	n = 0;
	c = 0;
	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (piece[x][y] == '.')
				y++;
			else if (piece[x][y] == '#' && conn(x, y, piece) > 0)
			{
				c = c + conn(x, y++, piece);
				n++;
			}
			else
				return (-1);
		}
	}
	return ((n == 4 && (c == 6 || c == 8)) ? 0 : -1);
}

int				check_tetris(t_etris tetris[27])
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
