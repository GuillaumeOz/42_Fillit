/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:48:08 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/24 20:36:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_letter(t_solve_datum *data, char c)
{
	int	i;
	int j;

	i = -1;
	while (++i < data->size)
	{
		j = -1;
		while (++j < data->size)
		{
			if (data->table[i][j] == c)
				return (1);
		}
	}
	return (0);
}

int		smallest_square(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

void	print_table(char **table, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(table[i][j]);
		ft_putchar('\n');
	}
}
