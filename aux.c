/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:18:22 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/27 13:13:31 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void		canonic_piece(char **piece, int col, int row,
						  int length, int width)
{
	int i;
	int j;

	i = 0;
	while (i < width)
		{
			ft_memmove(piece[i], piece[i + row] + col, length);
			j = 0;
			while (j < 4 - length)
				{
					piece[i][length + j] = '.';
					j++;
				}
			i++;
		}
	while (i < 4)
		{
			j = 0;
			while (j < 4)
				piece[i][j++] = '.';
			i++;
		}
}

void		canonic_position(char **piece, int col, int row,
						  int length, int width)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < width)
		{
			j = 0;
			k = 0;
			while (j < length)
				{
					if (piece[i + row][j + col] == '#')
						piece[i][k++] = j + 1;
					j++;
				}
			//piece[5][0] = width;
			//piece[5][1] = length;
			while (k < 4)
				piece[i][k++] = 0;
			i++;
		}
	while (i < 4)
		{
			j = 0;
			while (j < 4)
				piece[i][j++] = 0;
			i++;
		}
}

void   		piece_bounds(char **piece, int *col, int *row, 
						 int *length, int *width)
{
	int i;
	int ind;

	i = 0;
	*col = 4;
	*row = 4;
	*length = 0;
	*width = 0;
	while (i < 4)
		{
			if ((ind = ft_index('#', piece[i])) != 4)
				{
					*col = ft_min_int(*col, ind);
					*row = ft_min_int(*row, i);
					*length = ft_max_int(*length, ft_index_rev('#', piece[i]));
					*width += 1;
				}
			i++;
		}
	*length = *length + 1 - *col;
}

void		canonic_form(char ***tetris)
{
	int		i;
	int		col;
	int		row;
	int		length;
	int		width;

	i = 0;
	while (tetris[i])
		{
			piece_bounds(tetris[i], &col, &row, &length, &width);
			canonic_position(tetris[i++], col, row, length, width);
		}
}
