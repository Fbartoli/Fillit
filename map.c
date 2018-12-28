/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:47:52 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/28 12:52:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <stdio.h>

/* Check if it is possible to fit the tetrimino (**tetris) in the map*/
/* initialize the 16*16 map*/

int		init_map(char map[16][16])
{
	int i;

	i= 0;
	while (i < 16)
	{
		ft_memset(map[i], '.', 16);
		i++;
	}

	return (0);
}

int		is_available_map(t_etris *tetris, char map[16][16], int x, int y)
{
	int t;
	int i;

	printf("%d%d\n", x, y);
	i = 0;
	t = 0;
	if (map[y][x] != '.')
		is_available_map(*tetris, map, x + tetris->xy[i++]);
	else (fill_map )
	map[y][x] = '#';
	i++;
	return (0);
}
