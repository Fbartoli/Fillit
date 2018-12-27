/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:47:52 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/28 00:48:42 by flbartol         ###   ########.fr       */
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
		printf("%s\n", map[i]);
		i++;
	}

	return (0);
}

//int		fill_map(t_etris tetris[27], char map[16][16], int x, int y)
//{
	//int t;
//	int i;

//	t = 0;
	//while (tetris[t].piece[0][0] != 0)
	//{
		//if (map[y][x] == '.')
	//	{
		//	if (is_space_available(tetris [t],
		//	map[y + tetris[t].xy[i][0][x + tetris[t].xy[i][1]]]) == -1);
			//	return (0);
	//	}
//	}
//}
