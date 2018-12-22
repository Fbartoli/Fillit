/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:07:38 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/22 23:39:44 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <stdio.h>

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

int			input_to_tetris(int fd, char ***tetris)
{
	int 	i;
	int		j;
	ssize_t	rd;
	char	buff[5];

	i = 0;
	while (i != -1)
	{
		if (!(tetris[i] = (char**)malloc(5 * sizeof(char*))))
			return (-1);
		j = 0;
        while (j < 4)
		{
			if ((rd = read(fd, buff, 5)) != 5 || buff[4] != '\n')
			{
				//free_tetris(tetris, i ,j);
				return (0);
			}
			buff[4] = 0;
			if (!(tetris[i][j++] = strdup(buff)))
				return (-1);
		}
		tetris[i][j] = 0;
		i++;
		if (!(rd = read(fd, buff, 1)))
		{
			tetris[i] = 0;
			return (1);
		}
		if (buff[0] != '\n')
		{
			//free_tetris(tetris, i ,j);
			return (0);
		}
	}
	return (1);
}

int			main(int argc, char **argv)
{
//	char	buff[5];
	int		fd;
	char	***tetris;
//	int		n;

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1
		|| !(tetris = (char***)malloc(26 * sizeof(char **)))
		|| input_to_tetris(fd, tetris) == 0)
		return (print_error());
	printf("Stocked\n");

	for(size_t t = 0; t < 25; t++)
	{

		for(size_t y = 0; y < 5; y++)
		{
			printf("%s\n", tetris[t][y]);	/* code */
		}
	}
	if (check_tab(tetris) == -1)
		return(print_error());
	return(0);
}
