/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:53:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/01/05 18:53:27 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			print_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int			print_usage(void)
{
	write(1, "Usage: fillit fichier_cible\n", 28);
	return (0);
}

void		print_tetris(t_etris tetris[27])
{
	int i;
	int j;

	i = 0;
	while (tetris[i].piece[0][0] != 0)
	{
		j = 0;
		while (tetris[i].piece[j][0])
		{
			ft_putstr(tetris[i].piece[j]);
			ft_putchar('\n');
			j++;
		}
		i++;
		if (tetris[i].piece[0][0])
			ft_putchar('\n');
	}
}

void		print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_map)
	{
		ft_putnstr(map->map[i++], map->size_map);
		ft_putchar('\n');
	}
}
