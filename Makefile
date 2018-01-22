# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#              #
#    Updated: 2018/01/22 19:50:18 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c verification.c \
      prepare.c makebox.c fillthebox.c \
      utillity.c makemap.c filler.c


OBJ_SRC = $(SRC:.c=.o)
CFLAGS = -o $(NAME) -Wall -Werror -Wextra -I.

all: $(SRC)
	gcc $(CFLAGS) $(SRC)