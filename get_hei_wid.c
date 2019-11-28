/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hei_wid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 00:47:54 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/13 06:26:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_hei(t_tetri *head)
{
	int hei;
	int i;
	int j;

	hei = 0;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4 && j < 4)
		{
			if ((head->tetrimino)[j][i] == '#')
			{
				hei++;
				j++;
				i = -1;
			}
		}
	}
	return (hei);
}

int		get_wid(t_tetri *head)
{
	int wid;
	int i;
	int j;

	wid = 0;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4 && j < 4)
		{
			if ((head->tetrimino)[i][j] == '#')
			{
				wid++;
				j++;
				i = -1;
			}
		}
	}
	return (wid);
}

void	get_hei_wid(t_tetri **node)
{
	t_tetri *head;

	head = *node;
	head->hei = get_hei(head);
	head->wid = get_wid(head);
}
