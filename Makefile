CHECK = checker

PUSH = push_swap

GCC_FLAGS = gcc -c -Wall -Werror -Wextra

SRC = checker.c

HEADER_DIR = -I ./checker.h -I ./libft/libft.a

O_FILES = $(SRC:.c=.o)

all: $(CHECK)

$(CHECK):
	cd libft && make all
	$(GCC_FLAGS) $(SRC) $(HEADER_DIR) -o $(CHECK)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(CHECK)

re: fclean all

.PHONY: all clean fclean re