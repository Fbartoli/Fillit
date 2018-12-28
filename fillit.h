/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:08:14 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/28 11:20:01 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"


typedef struct s_point
{
	char		piece[5][5];
	int 		xy[4][2];
	int			width;
	int			length;

} 				t_etris;

int			print_error(void);
int			print_usage(void);
void		print_tetris(t_etris tetris[27]);
void        print_detailed_tetris(t_etris tetris[27]);
int			input_to_tetris(int fd, t_etris tetris[27]);
int			check_tetris(t_etris tetris[27]);
int			relative_position(char ***tetris);
int			init_map(char map[16][16]);
void        canonic_form(t_etris tetris[27]);
int			fill_map(t_etris tetris[27], char map[16][16], int x, int y);

#endif
