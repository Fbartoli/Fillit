/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:41:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 19:24:52 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int		root;
	long	square;

	root = 1;
	square = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (square < nb && root < 50000)
		{
			root++;
			square = root * root;
		}
		if (square == nb)
			return (root);
		else
			return (0);
	}
}

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
