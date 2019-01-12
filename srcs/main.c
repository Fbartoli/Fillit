/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:51:38 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/12 16:21:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_etris	tetris[27];
	t_map	map;
	char	buff[2];

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1
		|| input_to_tetris(fd, tetris) != 1)
		return (print_error());
	if (read(fd, buff, 1) != 0)
		return (print_error());
	if (check_tetris(tetris) == -1)
		return (print_error());
	canonic_form(tetris, &map);
	init_map(&map);
	init_size(tetris, &map);
	if (solver(tetris, &map) == -1)
		return (print_error());
	print_map(&map);
	return (0);
}
