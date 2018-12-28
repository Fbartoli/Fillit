/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:41:15 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/28 14:29:27 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_etris	tetris[27];
	t_map	map;
	int 	i;
	int k;
	int t = 0;

	map.size_map = 16;
	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1
		|| input_to_tetris(fd, tetris) != 1)
		return (print_error());
	write(1, "Stocked\n", 8);
	if (check_tetris(tetris) == -1)
		return (print_error());
	print_tetris(tetris);
	canonic_form(tetris, &map);
	write(1, "Modified tetris\n", 16);
	print_detailed_tetris(tetris);
	init_map(&map);
	print_map(&map);
	printf("map done\n");
	k = 0;
	while (tetris[t].piece[0][0] != 0)
	{
		if (is_available_map(&(tetris[t]), &map) == 0 && map.current_xy[0] < 16)
			put_in_map(&(tetris[t++]), &map);
		map.current_xy[0] += 1; 
	}
	print_map(&map);
	return (0);
}
