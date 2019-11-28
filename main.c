/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:07:08 by gozsertt          #+#    #+#             */
/*   Updated: 2019/06/17 16:58:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_node(t_tetri **node)
{
	t_tetri		*head;
	t_tetri		*prev;

	head = *node;
	while (head->previous_tetri != NULL)
		head = head->previous_tetri;
	while (head)
	{
		prev = head;
		head = head->next_tetri;
		free(prev);
	}
	free(head);
}

void	free_tab(char ***tab, int nb_tetrimino)
{
	char	**to_free;
	int		i;
	int		j;

	i = -1;
	if (nb_tetrimino == 27)
	{
		to_free = *tab;
		while (++i < nb_tetrimino)
			if (to_free[i])
				ft_strdel(&to_free[i]);
		free(to_free);
		return ;
	}
	if (tab != NULL)
		while (++i < nb_tetrimino)
		{
			j = -1;
			if (tab[i])
				while (++j < 4)
					ft_memdel((void*)&(tab[i][j]));
			free(tab[i]);
		}
}

void	print_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(EXIT_FAILURE);
}

void	print_err(void)
{
	ft_putstr_fd("error\n", 1);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_tetri			*node;
	char			***tab;
	int				nb_tetrimino;

	node = NULL;
	if (ac == 2)
	{
		if ((get_valid_input(&tab, av[1], &nb_tetrimino)) != EXIT_SUCCESS)
		{
			free_tab(tab, nb_tetrimino);
			print_err();
		}
		if ((build_node(&node, tab, nb_tetrimino)) != EXIT_SUCCESS)
		{
			free_tab(tab, nb_tetrimino);
			free_node(&node);
			print_err();
		}
		while (node->previous_tetri != NULL)
			node = node->previous_tetri;
		solve(node, nb_tetrimino);
		free_node(&node);
		exit(EXIT_SUCCESS);
	}
	print_usage();
}
