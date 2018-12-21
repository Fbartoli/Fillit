/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:08:14 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/21 16:29:27 by flbartol         ###   ########.fr       */
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
#include "./libft/libft.h"

int		print_error(void);
int		print_usage(void);
int		input_to_tetris(int fd, char ***tetris);
int		check_tab(char ***tab);

#endif
