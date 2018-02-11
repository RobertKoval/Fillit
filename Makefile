# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#              #
#    Updated: 2018/01/27 23:37:39 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = verification.c prepare.c makebox.c fillthebox.c \
		makemap.c filler.c main.c

OBJ = $(SRC:.c=.o)
INC = fillit.h

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
INCS = $(addprefix $(INC_DIR)/, $(INC))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -Iincludes
LDFLAGS = -L libft -lft

MAKELIB = cd libft && make

all: $(NAME)

$(NAME):
	$(MAKELIB)
	gcc -c $(SRCS) $(CFLAGS) $(CPPFLAGS)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ) $(OBJ_DIR)
	gcc $(OBJS) $(CFLAGS) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
