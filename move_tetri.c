/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 01:29:08 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/12 06:16:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_hor_spc(t_tetri **node)
{
	t_tetri	*head;
	int		hor;
	int		i;
	int		j;

	i = -1;
	hor = 0;
	head = *node;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (head->tetrimino[i][j] == '#')
				return (hor);
		}
		hor++;
	}
	return (hor);
}

int		get_ver_spc(t_tetri **node)
{
	t_tetri	*head;
	int		ver;
	int		i;
	int		j;

	i = -1;
	ver = 0;
	head = *node;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (head->tetrimino[j][i] == '#')
				return (ver);
		}
		ver++;
	}
	return (ver);
}

void	translate(t_tetri **node, int hor, int ver)
{
	t_tetri *head;
	int		i;
	int		j;

	if (ver == 0 && hor == 0)
		return ;
	i = -1;
	head = *node;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (head->tetrimino[i][j] == '#')
			{
				head->tetrimino[i - hor][j - ver] = '#';
				head->tetrimino[i][j] = '.';
			}
		}
	}
}

void	move_tetri(t_tetri **node)
{
	t_tetri	*head;
	int		hor;
	int		ver;

	head = *node;
	hor = get_hor_spc(&head);
	ver = get_ver_spc(&head);
	translate(&head, hor, ver);
}
