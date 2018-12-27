/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:41:15 by flbartol          #+#    #+#             */
/*   Updated: 2018/12/27 20:12:02 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_etris	tetris[27];
	char	map[16][16];

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1
		|| input_to_tetris(fd, tetris) != 1)
		return (print_error());
	write(1, "Stocked\n", 8);
	if (check_tetris(tetris) == -1)
		return (print_error());
	print_tetris(tetris);
//	canonic_form(tetris);
	//write(1, "newline\n", 8);
	//print_tetris_position(tetris);
//	write(1, "newline\n", 8);
//	init_map(map);
	//free_tetris(tetris, 26, 4);
	return (0);
}
