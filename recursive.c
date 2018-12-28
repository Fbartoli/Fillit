/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:30:58 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/28 15:55:43 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

int		solver(t_etris tetris[27], t_map *map)
{
	int *t;

	t = &map->nb_piece_placed;
	while (t != map->nb_tot_tetris)
	{
		if (tetris[*t].length > map->size_map - map->current_xy[1])
		{
			map->current_xy[0] += 1;
			map->current_xy[1] = 0;
		}
		if (tetris[*t].width > map->size_map - map->current_xy[0])
		{
			(*t)--;
			delete_tetris(&tetris[*t], &map, *t);
			map->current_xy[0] = map->position_piece[*t][0];
			map->current_xy[1] = (map->position_piece[*t][1]) + 1;
		}
		if (is_available_map(&(tetris[*t]), &map) == -1)
		{
			map->current_xy[1] += 1;	
		}
	}
}
