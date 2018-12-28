/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:47:52 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/28 14:22:25 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#include <stdio.h>

/* Check if it is possible to fit the tetrimino (**tetris) in the map*/
/* initialize the 16*16 map*/

int		init_map(t_map *map)
{
	int i;

	i= 0;
	while (i < 16)
	{
		ft_memset(map->map[i], '.', 16);
		i++;
	}
	map->nb_piece_placed = 0;
	map->current_xy[0] = 0;
	map->current_xy[1] = 0;
	return (0);
}

int		is_available_map(t_etris *tetris, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = map->current_xy[0];
	y = map->current_xy[1];
	while((map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]]) == '.' && i < 4)
		i++;
	if (i != 4)
		return (-1);
	printf("%d\n", i);
	return (0);
}

int		put_in_map(t_etris *tetris, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = map->current_xy[0];
	y = map->current_xy[1];
	while(i < 4)
	{
		map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]] = tetris->lettre;
		i++;
	}
	return (0);
}

int		delete_tetris(t_etris *tetris, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = map->current_xy[0];
	y = map->current_xy[1];
	while(i < 4)
	{
		map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]] = '.';
		i++;
	}
	return (0);
}
