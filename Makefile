# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 16:12:18 by ymohl-cl          #+#    #+#              #
#    Updated: 2014/02/26 10:03:18 by ymohl-cl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42_sh

LIBFT = -L libft/ -lft

LIBFTH = -I libft/

WFT = make -C libft/

LIB = libshell.a

WLIB = -L. -lshell

CC = gcc

CCB= llvm-gcc-4.2

GFLAG = -g3

FLAG = -Wall -Wextra -Werror

ADD = -ltermcap

SRC =	src_int/ft_minishell.c \
		src_int/ft_read.c \
		src_int/ft_check_key.c \
		src_int/ft_tputs.c \
		src_int/ft_termios.c \
		src_int/ft_filled_lste.c \
		src_int/ft_print_lste.c \
		src_int/ft_print_fd.c \
		src_int/ft_create_hst.c \
		src_int/get_next_line.c \
		src_int/ft_clean_thist.c \
		src_int/ft_write_on_file.c \
		src_int/ft_del_keyword.c \

OBJ = $(SRC:.c=.o)

.PHONY: all say clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $< -I. $(LIBFTH)
	@echo "\033[32m.\c\033[0m"

$(NAME): say $(OBJ)
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "\033[32m\tDONE !\033[0m"
	@$(WFT)
	@$(CC) $(FLAG) -o $(NAME) $(ADD) $(OJB) $(WLIB) $(LIBFT) -I.
	@echo "\033[32m\t$(NAME) project is compiled !\033[0m"

say:
	@echo "\033[33m\t'.' == One file is compiled\t\033[0m"
	@echo "\033[33m\t' ' == make: Nothing to be done for 'all'\t\033[0m"
	@echo "\033[32m\t$(LIB) compilation progress\t\c\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[32m\tRemove all objects from the $(LIB)\tDONE !\033[0m"

fclean: clean
	@$(WFT) fclean
	@rm -f $(NAME) $(LIB)
	@echo "\033[32m\tRemove $(LIB) and $(NAME)\t\tDONE !\033[0m"

re: fclean all
