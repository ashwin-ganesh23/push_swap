CHECK = checker

PUSH = push_swap

GCC_FLAGS = gcc -Wall -Werror -Wextra

SRC_CHECKER = ./src/checker.c
SRC_PUSH 	= ./src/push_swap.c

LIBFT = -L libft/ -lft

#HEADERS = -I ./includes/checker.h -I ./libft 
PHEADERS = -I ./includes/push_swap.h -I ./libft

O_FILES = $(SRC:.c=.o)

all: $(CHECK)

$(CHECK):
	cd libft && make all
	#$(GCC_FLAGS) $(SRC_CHECKER) $(HEADERS) $(LIBFT) -o $(CHECK)
	$(GCC_FLAGS) $(SRC_PUSH) $(PHEADERS) $(LIBFT) -o $(PUSH)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(CHECK) $(PUSH)

re: fclean all

.PHONY: all clean fclean re
