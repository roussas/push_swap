CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = push_swap

<<<<<<< HEAD
SRCS    = complex.c \
		  disorder.c \
		  ft_strncmp.c \
		  insertion.c \
		  n2.c \
		  medium.c \
		  ops_logic.c \
		  ops_rotate.c \
          ops_swap_push.c \
		  parse_args.c \
		  print_stack.c \
		  push_swap.c \
		  ranker.c \
		  stack_utils.c
OBJS    = $(SRCS:.c=.o)
DEPS	= $(SRCS:.c=.d)
=======
SRCS    = complex.c disorder.c insertion.c n2.c ops_logic.c ops_rotate.c \
          ops_swap_push.c print_stack.c push_swap.c stack_utils.c
OBJS    = $(SRCS:.c=.o)
>>>>>>> error_handle

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

<<<<<<< HEAD
-include $(DEPS)

.PHONY: all clean fclean re
=======
.PHONY: all clean fclean re
>>>>>>> error_handle
