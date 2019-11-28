/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:13:55 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/13 06:41:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetri_includ(t_tetri *node, t_solve_datum *data, int y, int x)
{
	int i;

	i = -1;
	if (((node->hei + y) > data->size) || ((node->wid + x) > data->size))
		return (0);
	while (++i != 4)
	{
		if (data->table[(node->y[i] + y)][(node->x[i] + x)] != '.')
			return (0);
	}
	return (1);
}

int		is_over(t_tetri *head, t_solve_datum *data)
{
	int i;

	i = 0;
	while (head != NULL && find_letter(data, head->letter))
		head = head->next_tetri;
	if (head == NULL)
		return (1);
	return (0);
}

int		place_tetri(t_tetri *head, t_solve_datum *data, int y, int x)
{
	if (is_over(head, data) == 1)
		return (1);
	if (head == NULL)
		return (1);
	while (y < data->size)
	{
		while (x < data->size)
		{
			if (tetri_includ(head, data, y, x) == 1)
			{
				write_tetri(head, data->table, y, x);
				if (place_tetri(head->next_tetri, data, 0, 0) == 1)
					return (1);
				remove_tetri(head, data);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int		resolve(t_tetri *head, t_solve_datum *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->size)
	{
		j = -1;
		while (++j < data->size)
			data->table[i][j] = '.';
	}
	return (place_tetri(head, data, 0, 0));
}

void	solve(t_tetri *head, int nb_tetrimino)
{
	t_solve_datum	*data;
	char			**table;
	int				size;
	int				i;

	i = -1;
	size = smallest_square(nb_tetrimino * 4);
	if (!(data = (t_solve_datum *)ft_memalloc(sizeof(t_solve_datum))))
		return ;
	if (!(table = (char **)ft_memalloc(sizeof(char*) * 27)))
		return ;
	while (++i < 27)
		if (!(table[i] = (char *)ft_memalloc(sizeof(char) * 27)))
			return ;
	data->table = table;
	data->size = size;
	while (resolve(head, data) == 0 && (data->size < 27))
		data->size++;
	print_table(data->table, data->size);
	ft_memdel((void *)(&data));
	free_tab(&table, 27);
}
