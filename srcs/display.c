/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:53:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/01/13 18:40:01 by flbartol         ###   ########.fr       */
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
