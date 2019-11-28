/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_test_and_fill_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:55:55 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/17 16:58:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_contacts(char **tab, int y, int x)
{
	int contacts;

	contacts = 0;
	if (y > 0 && tab[y - 1][x] == '#')
		contacts++;
	if (y < 3 && tab[y + 1][x] == '#')
		contacts++;
	if (x > 0 && tab[y][x - 1] == '#')
		contacts++;
	if (x < 3 && tab[y][x + 1] == '#')
		contacts++;
	return (contacts);
}

int	check_shape(char ***tmp, int i)
{
	int x;
	int y;
	int res;

	x = 0;
	y = -1;
	res = 0;
	while (++y < 4)
	{
		while (x < 4)
		{
			if (tmp[i][y][x] == '#')
				res += count_contacts(tmp[i], y, x);
			x++;
		}
		x = 0;
	}
	if (res == 6 || res == 8)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	fill_tab(char ***tmp, int curr_tetri, char *buf, int buf_i)
{
	int i;
	int y;
	int x;

	i = -1;
	y = 0;
	x = 0;
	if (!((tmp[curr_tetri]) = (char **)ft_memalloc(sizeof(char*) * 4)))
		exit(EXIT_FAILURE);
	while (++i < 4)
	{
		if (!((tmp[curr_tetri][y]) = (char *)ft_memalloc(sizeof(char) * 4)))
			exit(EXIT_FAILURE);
		x = 0;
		while (buf[buf_i] != '\n')
		{
			tmp[curr_tetri][y][x] = buf[buf_i];
			buf_i++;
			x++;
		}
		if (buf[buf_i] == '\n')
			buf_i++;
		y++;
	}
	return (EXIT_SUCCESS);
}

int	check_char(char *str, int i)
{
	int	pointcount;
	int hashcount;
	int linecount;

	pointcount = 0;
	hashcount = 0;
	linecount = 0;
	while (str[i]
	&& (str[i] != '\n' || (str[i + 1] != '\n' && str[i + 1] != '\0')))
	{
		if (str[i] == '.')
			pointcount++;
		if (str[i] == '#')
			hashcount++;
		if (str[i] == '\n')
			linecount++;
		i++;
	}
	if (str[i] == '\n')
		linecount++;
	if ((pointcount + hashcount + linecount - 1) == 19
	&& pointcount == 12 && hashcount == 4 && linecount == 4)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ad_test_and_fill_tab(char ***tab, char *str, int nb_tetrimino)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < nb_tetrimino)
	{
		if (((check_char(str, j)) || (fill_tab(tab, i, str, j))
			|| (check_shape(tab, i))) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		while (str[j] != '\n' || (str[j + 1] != '\n' && str[j + 1] != '\0'))
		{
			if (str[j + 1] == '\0')
				break ;
			j++;
		}
		if (str[j + 1] != '\0')
			j += 2;
	}
	return (EXIT_SUCCESS);
}
