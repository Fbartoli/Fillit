/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:47:52 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 19:37:11 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_size(t_etris tetris[27], t_map *map)
{
	int i;
	int w;
	int l;
	int s;

	i = 0;
	w = 0;
	l = 0;
	s = ft_max_int(tetris[0].length, tetris[0].width);
	s = ft_max_int(ft_sqrt(4 * map->nb_tot_tetris), s);
	while (i < map->nb_tot_tetris)
	{
		w = tetris[i].width == 4 ? w + 1 : w;
		l = tetris[i].length == 4 ? l + 1 : l;
		i++;
	}
	map->size_map = (w > 7 || l > 7) ? ft_max_int(s, 8) : s;
}

int		init_map(t_map *map)
{
	int i;

	i = 0;
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
	while ((map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]]) == '.'
			&& i < 4)
		i++;
	if (i != 4)
		return (-1);
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
	while (i < 4)
	{
		map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]] = tetris->lettre;
		i++;
	}
	return (0);
}

int		delete_tetris(t_etris *tetris, t_map *map, int t)
{
	int i;
	int x;
	int y;

	i = 0;
	x = map->position_piece[t][0];
	y = map->position_piece[t][1];
	while (i < 4)
	{
		map->map[x + tetris->xy[i][0]][y + tetris->xy[i][1]] = '.';
		i++;
	}
	return (0);
}
