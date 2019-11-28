/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:01:06 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/13 06:41:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_y_x(t_tetri **node)
{
	t_tetri	*head;
	int		y_i;
	int		x_i;
	int		count;

	y_i = -1;
	x_i = -1;
	count = 0;
	head = *node;
	while (++y_i < 4)
	{
		while (++x_i < 4)
		{
			if (head->tetrimino[y_i][x_i] == '#')
			{
				head->y[count] = y_i;
				head->x[count] = x_i;
				count++;
			}
		}
		if (count == 4)
			break ;
		x_i = -1;
	}
}

void	creat_node(t_tetri **node)
{
	t_tetri *head;

	head = *node;
	move_tetri(&head);
	get_hei_wid(&head);
	get_y_x(&head);
}

int		build_node(t_tetri **node, char ***tab, int nb_tetri)
{
	t_tetri	*head;
	t_tetri *tmp;
	char	letter;
	int		i;

	i = -1;
	letter = 'A';
	tmp = NULL;
	head = *node;
	while (++i < nb_tetri)
	{
		if (!(head = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
			return (EXIT_FAILURE);
		head->previous_tetri = tmp;
		if (tmp != NULL)
			tmp->next_tetri = head;
		head->tetrimino = tab[i];
		head->letter = letter;
		letter++;
		creat_node(&head);
		tmp = head;
	}
	head->next_tetri = NULL;
	*node = head;
	return (EXIT_SUCCESS);
}
