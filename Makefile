NAME	    = push_swap

SRC_DIR		= src
OBJ_DIR		= obj

PARSE_SRCS	= src/parse/disorder.c \
			  src/parse/error_handle.c \
			  src/parse/ft_split.c \
			  src/parse/atoi_utils.c \
			  src/parse/parse_args.c \
			  src/parse/parse_arg_extra.c 
SORT_SRCS	= src/sort/complex.c \
			  src/sort/insertion.c \
			  src/sort/medium.c
STACK_SRCS  = src/stack/ops_logic.c \
			  src/stack/ops_rotate.c \
			  src/stack/ops_swap_push.c \
			  src/stack/stack_utils.c \
			  src/stack/extra_utils.c 
SRCS		= src/push_swap.c \
			  $(PARSE_SRCS) \
			  $(SORT_SRCS) \
			  $(STACK_SRCS)
OBJS    	= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Isrc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re