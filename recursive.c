/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:30:58 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 16:55:28 by flbartol         ###   ########.fr       */
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

		if (tetris[*t].length > map->size_map - map->current_xy[1])
		{
			map->current_xy[0] += 1;
			map->current_xy[1] = 0;
		}
		if (tetris[*t].width > map->size_map - map->current_xy[0])
		{
			*t -= 1;
			delete_tetris(&tetris[*(t)], map, *t);
			map->current_xy[0] = map->position_piece[*t][0];
			map->current_xy[1] = map->position_piece[*t][1] + 1;
			if (*t == 0 && tetris[0].length > map->size_map - map->current_xy[1] && tetris[0].width == map->size_map - map->current_xy[0]) 
			{
				if (map->size_map > 15)
					return(-1);
				map->size_map += 1;
				map->current_xy[0] = 0;
				map->current_xy[1] = 0;
			}
		}
		else if (is_available_map(&(tetris[*t]), map) == -1
			&& map->current_xy[1] < map->size_map)
			map->current_xy[1] += 1;
		else
		{
			map->position_piece[*t][0] = map->current_xy[0];
			map->position_piece[*t][1] = map->current_xy[1];
			put_in_map(&tetris[*t], map);
			map->current_xy[0] = 0;
			map->current_xy[1] = 0;
			*t += 1;
		}
	}
	return (0);
}
