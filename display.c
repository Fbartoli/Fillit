/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 display.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: ftrujill <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/12/27 12:16:39 by ftrujill		   #+#	  #+#			  */
/*   Updated: 2018/12/27 19:58:25 by flbartol         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

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

void		print_line_position(char *str)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < 4)
	{
		k++;
		if (k  == str[l])
		{
			ft_putstr("#");
			l++;
		}
		else
			ft_putstr(".");
	}
}

void		print_tetris_position(char ***tetris)
{
	int i;
	int j;

	i = 0;
	while (tetris[i])
	{
		j = 0;
		while (tetris[i][j])
		{
			print_line_position(tetris[i][j]);
			ft_putchar('\n');
			j++;
		}
		i++;
		if (tetris[i])
			ft_putchar('\n');
	}
}
