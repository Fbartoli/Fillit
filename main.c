/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:41:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 12:21:56 by flbartol         ###   ########.fr       */
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

	map.size_map = 4;
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
	printf("map done\n");
	if (solver(tetris, &map)== -1)
		return(print_error());
	print_map(&map);
	return (0);
}
