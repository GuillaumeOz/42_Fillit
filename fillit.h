/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:43:03 by gozsertt          #+#    #+#             */
/*   Updated: 2019/08/24 15:42:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 1024

typedef	enum	e_booleen
{
	no,
	yes
}				t_bool;

typedef struct	s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x[4];
	int					y[4];
	int					hei;
	int					wid;
	struct s_tetrimino	*previous_tetri;
	struct s_tetrimino	*next_tetri;
}				t_tetri;

typedef struct	s_solve_datum
{
	int			size;
	char		**table;
}				t_solve_datum;

void			*ft_memalloc(size_t size);
void			ft_memdel(void **p);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
void			ft_strdel(char **p);

void			print_err(void);
void			print_usage(void);
void			free_tab(char ***tab, int nb_tetrimino);
void			free_node(t_tetri **head);

int				get_valid_input(char ****tab, char *argv, int *nb_tetrimino);
int				count_tetrimino(char *str, int *nb_bytes);
int				basic_test(char *str);

int				ad_test_and_fill_tab(char ***tab, char *str, int nb_tetrimino);
int				check_char(char *str, int index);
int				fill_tab(char ***tmp, int curr_tetri, char *buf, int buf_i);
int				check_shape(char ***tmp, int i);
int				count_contacts(char **tab, int i, int j);

void			get_y_x(t_tetri **head);
int				build_node(t_tetri **node, char ***tab, int nb_tetri);

int				get_ver_spc(t_tetri **node);
int				get_hor_spc(t_tetri **node);
void			translate(t_tetri **node, int hor, int ver);
void			move_tetri(t_tetri **head);

int				get_hei(t_tetri *head);
int				get_wid(t_tetri *head);
void			get_hei_wid(t_tetri **head);

void			solve(t_tetri *head, int nb_tetrimino);
int				resolve(t_tetri *head, t_solve_datum *data);
int				place_tetri(t_tetri *head, t_solve_datum *data, int y, int x);
int				is_over(t_tetri *head, t_solve_datum *table);
int				tetri_includ(t_tetri *node, t_solve_datum *data, int y, int x);

void			print_table(char **table, int size);
int				smallest_square(int nb);
int				find_letter(t_solve_datum *data, char c);

void			remove_tetri(t_tetri *tetri, t_solve_datum *data);
void			write_tetri(t_tetri *node, char **table, int x, int y);
#endif
