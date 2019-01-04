/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:30:58 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/04 12:56:07 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

int		solver(t_etris tetris[27], t_map *map)
{
	int *t;

	t = &map->nb_piece_placed;
	while (*t != map->nb_tot_tetris)
	{
		if ((tetris[*t].length > map->size_map - map->current_xy[1] && map->current_xy[0] < map->size_map - 1))
		{
			map->current_xy[0] += 1;
			map->current_xy[1] = 0;
		}
		else if ((tetris[*t].width > map->size_map - map->current_xy[0]) && (map->current_xy[1] < map->size_map - 1))
		{
			*t -= 1;
			delete_tetris(&tetris[*(t)], map, *t);
			map->current_xy[0] = map->position_piece[*t][0];
			map->current_xy[1] = (map->position_piece[*t][1]) + 1;
		}
		else if (is_available_map(&(tetris[*t]), map) == -1
			&& map->current_xy[1] < map->size_map - 1)
			map->current_xy[1] += 1;
		else if (is_available_map(&(tetris[*t]), map) == 0)
		{
			map->position_piece[*t][0] = map->current_xy[0];
			map->position_piece[*t][1] = map->current_xy[1];
			put_in_map(&tetris[*t], map);
			map->current_xy[0] = 0;
			map->current_xy[1] = 0;
			*t += 1;
		}
		else
		{
			if (map->size_map > 16)
				return(-1);
			map->size_map += 1;
			map->current_xy[0] = 0;
			map->current_xy[1] = 0;
		}
	}
	return (0);
}