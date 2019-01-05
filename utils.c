/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:35:35 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/05 20:09:30 by ftrujill         ###   ########.fr       */
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
		return (root);
	}
}
