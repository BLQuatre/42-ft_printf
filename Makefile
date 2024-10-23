# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 13:09:18 by cauvray           #+#    #+#              #
#    Updated: 2024/10/23 23:44:39 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRC_DIR	= srcs
OBJ_DIR	= objs
INC_DIR	= includes

_SRCS = ft_hex_utils.c \
		ft_int_utils.c \
		ft_printf_utils.c \
		ft_printf_params.c \
		ft_printf_c.c \
		ft_printf_s.c \
		ft_printf_id.c \
		ft_printf_x.c \
		ft_printf_u.c \
		ft_printf_p.c \
		ft_printf.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

_OBJS = $(_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(_OBJS))

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C libft
	cp libft/libft.a .
	mv libft.a $@
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -Iincludes $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re:	fclean all

bonus: re

test: all
	$(CC) $(CFLAGS) .tests/main.c -L. -lftprintf -o main
	clear && ./main

.PHONY:	all clean fclean re