CC      = cc
CFLAGS  = -Wall -Wextra -Werror -MMD -MP
NAME    = push_swap

SRCS    = complex.c \
		  disorder.c \
		  insertion.c \
		  n2.c \
		  ops_logic.c \
		  ops_rotate.c \
          ops_swap_push.c \
		  print_stack.c \
		  push_swap.c \
		  stack_utils.c
OBJS    = $(SRCS:.c=.o)
DEPS	= $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
