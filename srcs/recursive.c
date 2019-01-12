/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:30:58 by flbartol          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/12 16:10:32 by flbartol         ###   ########.fr       */
=======
/*   Updated: 2019/01/07 12:30:56 by flbartol         ###   ########.fr       */
>>>>>>> c59836ffc46d1afa14016b9eaa539c1e4f3b2ba2
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		put_and_reset(t_etris *tetris, t_map *map, int *t)
{
	map->position_piece[*t][0] = map->current_xy[0];
	map->position_piece[*t][1] = map->current_xy[1];
	put_in_map(tetris, map);
	map->current_xy[0] = 0;
	map->current_xy[1] = 0;
	*t += 1;
}

static void		increase_size(t_map *map)
{
	map->size_map += 1;
	map->current_xy[0] = 0;
	map->current_xy[1] = 0;
}

static void		move_down(t_map *map)
{
	map->current_xy[0] += 1;
	map->current_xy[1] = 0;
}

int				solver(t_etris tetris[27], t_map *map)
{
	int *t;

	t = &map->nb_piece_placed;
	while (*t != map->nb_tot_tetris)
	{
		if (tetris[*t].length > map->size_map - map->current_xy[1])
			move_down(map);
		if (tetris[*t].width > map->size_map - map->current_xy[0])
		{
			delete_tetris(&tetris[--*t], map, *t);
			map->current_xy[0] = map->position_piece[*t][0];
			map->current_xy[1] = map->position_piece[*t][1] + 1;
			if (*t == 0
				&& tetris[0].width == map->size_map - map->current_xy[0]
				&& tetris[0].length == map->size_map - map->current_xy[1] + 1)
				increase_size(map);
		}
		else if (is_available_map(&(tetris[*t]), map) == -1)
			map->current_xy[1] += 1;
		else
			put_and_reset(&(tetris[*t]), map, t);
	}
	return (0);
}
