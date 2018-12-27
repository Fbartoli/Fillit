/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:18:22 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/27 21:52:09 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		canonic_piece(t_etris *tetris, int col, int row)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->width)
		{
			ft_memmove(tetris->piece[i],
					   tetris->piece[i + row] + col, tetris->length);
			j = 0;
			while (j < 4 - tetris->length)
				{
					tetris->piece[i][tetris->length + j] = '.';
					j++;
				}
			i++;
		}
	while (i < 4)
		{
			j = 0;
			while (j < 4)
				tetris->piece[i][j++] = '.';
			i++;
		}
}

void        piece_coords(t_etris *tetris, int col, int row)
{
    int i;
    int j;
    int k;

    i = 0;
	k = 0;
    while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->length)
		{
			if (tetris->piece[i + row][j + col] == '#')
			{
				tetris->xy[k][0] = i;
				tetris->xy[k++][1] = j;
			}
			j++;
		}
		i++;
	}			
}

void   		canonic_position(t_etris *tetris)
{
	int j;
	int col;
	int row;
	int ind;

	j = 0;
	col = 4;
	row = 4;
	tetris->length = 0;
	tetris->width = 0;
	while (j < 4)
		{
			if ((ind = ft_index('#', tetris->piece[j])) != 4)
				{
					col = ft_min_int(col, ind);
					row = ft_min_int(row, j);
					tetris->length = ft_max_int(tetris->length, ft_index_rev('#', tetris->piece[j]));
					tetris->width += 1;
				}
			j++;
		}
	tetris->length += 1 - col;
	piece_coords(tetris, col, row);
	canonic_piece(tetris, col, row);
}

void		canonic_form(t_etris tetris[27])
{
	int i;

	i = 0;
	while (tetris[i].piece[0][0])
		canonic_position(&(tetris[i++]));
}
