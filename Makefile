# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 09:00:04 by gozsertt          #+#    #+#              #
#    Updated: 2019/06/13 06:41:58 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	ad_test_and_fill_tab.c\
		build_node.c\
		get_hei_wid.c\
		get_valid_input.c\
		move_tetri.c\
		place_remove_write.c\
		solve.c\
		tools.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_putchar.c\
		ft_putendl.c\
		ft_putstr_fd.c\
		ft_strdel.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		main.c\

OBJECTS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra 

all : $(NAME)

$(NAME) :
	$(GCC) -c $(SRCS)
	$(GCC) -o $(NAME) $(OBJECTS)

clean :
	/bin/rm -Rf $(OBJECTS)

fclean : clean
	/bin/rm -Rf $(NAME)

re : fclean all

.PHONY : clean fclean re