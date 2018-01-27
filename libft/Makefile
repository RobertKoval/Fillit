# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 22:46:40 by rkoval            #+#    #+#              #
#    Updated: 2018/01/27 22:47:23 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_digilen.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
			ft_tolower.c ft_toupper.c ft_wordcount.c

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

all: $(NAME)
	
$(NAME):
	gcc $(CFLAGS) -c $(SRCS) $(CPPFLAGS)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ) $(OBJ_DIR)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
