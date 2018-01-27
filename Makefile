# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robert <robert@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#              #
#    Updated: 2018/01/27 23:14:25 by robert           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = verification.c prepare.c makebox.c fillthebox.c \
		makemap.c filler.c main.c

OBJ = $(SRC:.c=.o)
INC = libft.h

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
INCS = $(addprefix $(INC_DIR)/, $(INC))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -Iincludes
LDFLAGS = -L./libft -llibft.a

MAKELIB = cd libft && make

all: $(NAME)

$(NAME):
	$(MAKELIB)
	gcc $(CFLAGS) -c $(SRCS) $(CFLAGS)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ) $(OBJ_DIR)
	gcc $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
