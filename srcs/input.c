/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:07:38 by ftrujill          #+#    #+#             */
/*   Updated: 2019/01/12 16:26:23 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			input_to_tetris(int fd, t_etris tetris[27])
{
	int		i;
	int		j;
	char	buff[5];

	i = 0;
	while (i < 26)
	{
		j = 0;
		while (j < 4)
		{
			if (read(fd, buff, 5) != 5 || buff[4] != '\n')
				return (-1);
			buff[4] = 0;
			ft_memmove(tetris[i].piece[j++], buff, 5);
		}
		ft_memset(tetris[i++].piece[j], 0, 5);
		if (!(read(fd, buff, 1)))
		{
			ft_memset(tetris[i].piece, 0, 5);
			return (1);
		}
		if (buff[0] != '\n')
			return (-1);
	}
	return (1);
}
