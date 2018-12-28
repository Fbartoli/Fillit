/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 display.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: ftrujill <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/12/27 12:16:39 by ftrujill		   #+#	  #+#			  */
/*   Updated: 2018/12/28 13:14:07 by ftrujill         ###   ########.fr       */
/*																			  */
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

void        print_detailed_tetris(t_etris tetris[27])
{
    int i;
    int j;
	int k;

    i = 0;
    while (tetris[i].piece[0][0] != 0)
    {
        j = 0;
        while (tetris[i].piece[j][0])
            printf("%s\n", tetris[i].piece[j++]);
		printf("Length: %d, Width: %d, Coords: ", tetris[i].length, tetris[i].width);
		k = 0;
		while (k < 4)
		{
			printf("(%d, %d) ", tetris[i].xy[k][0], tetris[i].xy[k][1]);
			k++;
		}
		printf("\n");
		i++;
        if (tetris[i].piece[0][0])
            ft_putchar('\n');
    }
}

void		print_map(char map[16][16], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnstr(map[i++], size);
		ft_putchar('\n');
	}
}
