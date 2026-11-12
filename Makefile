CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = push_swap

SRCS    = complex.c \
		  disorder.c \
		  error_handle.c \
		  ft_atol.c \
		  ft_split.c \
		  ft_strncmp.c \
		  insertion.c \
		  medium.c \
		  n2.c \
		  ops_logic.c \
		  ops_rotate.c \
          ops_swap_push.c \
		  parse_args.c \
		  print_stack.c \
		  push_swap.c \
		  ranker.c \
		  stack_utils.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# TODO: deal with libft.h
# 1. take all function prototypes into push_swap.h
# 2. or make library
# otherwise might need to argue why there are so many prototypes 
# in libft.h even though these functions are not used
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
