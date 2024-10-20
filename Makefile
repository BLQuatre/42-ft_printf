# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 13:09:18 by cauvray           #+#    #+#              #
#    Updated: 2024/10/19 03:07:36 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS += -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

_SRCS = ft_printf.c \
		ft_printf_hex.c
SRCS = $(addprefix $(SRC_DIR)/,$(_SRCS))

_OBJS = $(_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(_OBJS))

all:	$(NAME)

$(NAME): $(OBJS)
	@$(MAKE) bonus -C libft
	@cp libft/libft.a .
	@mv libft.a $@
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -Iincludes $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean:	clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft

re:	fclean all

test: all
	@$(CC) $(CFLAGS) main.c -L. -lftprintf -o main
	@clear && ./main && rm ./main

.PHONY:	all clean fclean re