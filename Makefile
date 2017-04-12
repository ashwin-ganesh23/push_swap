CHECK = checker

PUSH = push_swap

GCC_FLAGS = gcc -Wall -Werror -Wextra

SRC = checker.c

LIBFT = -L libft/ -lft

HEADERS = -I ./checker.h -I ./libft

O_FILES = $(SRC:.c=.o)

all: $(CHECK)

$(CHECK):
	cd libft && make all
	$(GCC_FLAGS) $(SRC) $(HEADERS) $(LIBFT) -o $(CHECK)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(CHECK)

re: fclean all

.PHONY: all clean fclean re
