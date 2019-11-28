/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:32:51 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/17 17:30:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	basic_test(char *s)
{
	int		i;
	int		linecount;
	t_bool	enter;

	i = -1;
	linecount = 0;
	enter = no;
	while (s[++i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n' && s[i] != '\0')
			return (EXIT_FAILURE);
		if (s[i] == '\n')
			linecount++;
		if (linecount == 4)
		{
			if (s[i + 1] != '\n' && s[i + 1] != '\0')
				return (EXIT_FAILURE);
			if (s[i + 1] == '\n')
				i++;
			linecount = 0;
			enter = yes;
		}
	}
	return ((linecount == 0 && enter == yes) ? EXIT_SUCCESS : EXIT_FAILURE);
}

int	count_tetrimino(char *s, int *nb_bytes)
{
	int i;
	int j;
	int nb_tetrimino;

	i = -1;
	j = 0;
	nb_tetrimino = 0;
	while (s[++i])
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetrimino++;
	*nb_bytes = i;
	i = -1;
	while (++i < nb_tetrimino)
	{
		if (check_char(s, j) != EXIT_SUCCESS)
			return (-1);
		while (s[j] != '\n' || (s[j + 1] != '\n' && s[j + 1] != '\0'))
			if (s[++j + 1] == '\0')
				break ;
		if (s[j + 1] != '\0')
			j += 2;
	}
	return (nb_tetrimino);
}

int	get_valid_input(char ****tab, char *argv, int *nb_tetrimino)
{
	char	***tmp;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		nb_bytes;

	if (((fd = open(argv, O_RDONLY)) == -1))
		return (EXIT_FAILURE);
	*nb_tetrimino = 0;
	nb_bytes = read(fd, buf, BUFF_SIZE);
	buf[nb_bytes] = '\0';
	nb_bytes = 0;
	if ((*nb_tetrimino = count_tetrimino(buf, &nb_bytes)) == -1)
		return (EXIT_FAILURE);
	if (nb_bytes > 545 || (*nb_tetrimino * 20 + *nb_tetrimino - 1) != nb_bytes)
		return (EXIT_FAILURE);
	if (basic_test(buf) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (!(tmp = (char ***)ft_memalloc(sizeof(char**) * (*nb_tetrimino))))
		return (EXIT_FAILURE);
	*tab = tmp;
	if (ad_test_and_fill_tab(tmp, buf, *nb_tetrimino) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
