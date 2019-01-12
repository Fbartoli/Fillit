/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/12/27 15:41:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 20:32:24 by flbartol         ###   ########.fr       */
=======
/*   Created: 2019/01/07 12:51:38 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/07 12:51:42 by flbartol         ###   ########.fr       */
>>>>>>> c59836ffc46d1afa14016b9eaa539c1e4f3b2ba2
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_etris	tetris[27];
	t_map	map;

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1
		|| input_to_tetris(fd, tetris) != 1)
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
