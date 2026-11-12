CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = push_swap

SRCS    = complex.c disorder.c error_handle.c ft_split .c insertion.c medium.c ops_logic.c ops_rotate.c \
          ops_swap_push.c print_stack.c push_swap.c stack_utils.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re