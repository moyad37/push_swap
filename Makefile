SRCS            = push_swap.c error.c check.c utils.c utils2.c start_sort.c swap.c \
					rotate.c revers_rotate.c push.c easy_sort.c find_min_utils.c \
					hard_sort.c

OBJS            = $(SRCS:.c=.o)

NAME     = push_swap

LIBFT_NAME      = ./libft/source/libft.a

CC              = cc

RM              = rm -f

CFLAGS = -Wall -Wextra -Werror


all:            $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	$(MAKE) all -C ./libft/source

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT_NAME)



clean:
	$(MAKE) clean -C ./libft/source
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft/source
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
