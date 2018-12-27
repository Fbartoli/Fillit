/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:47:52 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/27 19:34:57 by flbartol         ###   ########.fr       */
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
