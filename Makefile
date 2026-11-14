NAME	    = push_swap

SRC_DIR		= src
OBJ_DIR		= obj

BENCH_SRCS	= src/bench/bench.c \
			  src/bench/disorder.c \
			  src/bench/ft_uitoa.c \
			  src/bench/write_counts.c
PARSE_SRCS	= src/parse/error_handle.c \
			  src/parse/ft_atol.c \
			  src/parse/ft_split.c \
			  src/parse/ft_strncmp.c \
			  src/parse/parse_args.c \
			  src/parse/ranker.c
SORT_SRCS	= src/sort/complex.c \
			  src/sort/insertion.c \
			  src/sort/medium.c \
			  src/sort/sort.c
STACK_SRCS  = src/stack/ops_logic.c \
			  src/stack/ops_rotate.c \
			  src/stack/ops_swap_push.c \
			  src/stack/print_stack.c \
			  src/stack/stack_utils.c
SRCS		= src/push_swap.c \
			  $(BENCH_SRCS) \
			  $(PARSE_SRCS) \
			  $(SORT_SRCS) \
			  $(STACK_SRCS)
OBJS    	= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Isrc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c src/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
