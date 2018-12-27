/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:07:38 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/27 20:01:36 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

int			free_tetris(char ***tetris, int i, int j)
{
	int k;
	int l;

	k = 0;
	while (k <= i && tetris[k])
	{
		l = 0;
		while (l < (k == i ? j : 4))
			free((tetris[k])[l++]);
		free (tetris[k++]);
	}
	free(tetris);
	return (0);
}

int			input_to_tetris(int fd, t_etris tetris[27])
{
	int 	i;
	int		j;
	ssize_t	rd;
	char	buff[5];

	i = 0;
	while (i != -1)
	{
		j = 0;
        while (j < 4)
		{
			if ((rd = read(fd, buff, 5)) != 5 || buff[4] != '\n')
				return(-1);
		buff[4] = 0;
		ft_memmove(tetris[i].piece[j++], buff, 5);
		}
		ft_memset(tetris[i++].piece[j], 0, 5); 
		if (!(rd = read(fd, buff, 1)))
		{
			ft_memset(tetris[i].piece, 0, 5);
			return (1);
		}
		if (buff[0] != '\n')
			return (-1);
	}
	return (1);
}

