# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#              #
#    Updated: 2018/01/23 19:06:18 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = verification.c prepare.c makebox.c fillthebox.c \
      utillity.c makemap.c filler.c main.c
OBJ_SRC = $(SRC:.c=.o)
OFLAGS = -c -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):
	gcc $(OFLAGS) $(SRC)
	gcc $(OBJ_SRC) -o $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
