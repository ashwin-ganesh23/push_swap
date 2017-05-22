CHECK = checker

PUSH = push_swap

GCC_FLAGS = gcc -Wall -Werror -Wextra

SRC_CHECKER = 	./src/checker/checker.c
SRC_PUSH 	= 	./src/push_swap/push_swap.c
SRC_PUSH 	+=	./src/push_swap/initialize_ledger.c
SRC_PUSH 	+=	./src/push_swap/linked_list.c
SRC_PUSH 	+=	./src/push_swap/merge_sort.c
SRC_PUSH 	+=	./src/push_swap/parse_args.c
SRC_PUSH 	+=	./src/push_swap/push.c
SRC_PUSH 	+=	./src/push_swap/swap.c
SRC_PUSH 	+=	./src/push_swap/rotate.c
SRC_PUSH 	+=	./src/push_swap/reverse_rotate.c
SRC_PUSH 	+=	./src/push_swap/solver.c
SRC_PUSH 	+=	./src/push_swap/big_solver.c
SRC_PUSH	+=	./src/push_swap/small_solver.c

LIBFT = -L libft/ -lft

HEADERS = -I ./includes/checker.h -I ./libft
PHEADERS = -I ./includes/push_swap.h -I ./libft

O_FILES = $(SRC:.c=.o)

all: $(PUSH)

$(PUSH):
	cd libft && make all
	$(GCC_FLAGS) $(SRC_CHECKER) $(HEADERS) $(LIBFT) -o $(CHECK)
	$(GCC_FLAGS) $(SRC_PUSH) $(PHEADERS) $(LIBFT) -o $(PUSH)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(CHECK) $(PUSH)

re: fclean all

.PHONY: all clean fclean re
