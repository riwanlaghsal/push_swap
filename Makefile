NAME        = push_swap
CC          = cc
CFLAGS      = -g3 -Wall -Wextra -Werror -I.

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = push_swap.c \
              init_stacks.c \
              list_utils.c \
	      tab_utils.c \
	      rules_back.c \
	      rules_front.c \
	      rules_front2.c \
	      radix_sort.c \

OBJS        = $(SRCS:.c=.o)

HEADERS     = push_swap.h

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
