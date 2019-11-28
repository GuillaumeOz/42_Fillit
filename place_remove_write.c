/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_remove_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:08:00 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/13 06:41:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		write_tetri(t_tetri *node, char **table, int y, int x)
{
	int		i;

	i = -1;
	while (++i != 4)
		table[(node->y[i] + y)][(node->x[i] + x)] = node->letter;
}

void		remove_tetri(t_tetri *tetri, t_solve_datum *data)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < data->size)
	{
		while (++j < data->size)
		{
			if (data->table[i][j] == tetri->letter)
				data->table[i][j] = '.';
		}
		j = -1;
	}
}
