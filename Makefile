BASE_SRC = main.c
LIB = libft.a
OBJ_SRC = $(BASE_SRC:.c=.o)
CFLAGS = -o $(OUTPUT) $(BASE_SRC) -Wall -Werror -Wextra -I. -L. -lft
OUTPUT = fillit
all: 
	gcc $(CFLAGS) 
clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all
