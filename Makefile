SRCS            = push_swap.c error.c check.c utils.c init.c start_sort.c swap.c \
					rotate.c revers_rotate.c push.c easy_sort.c find_min_utils.c 

OBJS            = $(SRCS:.c=.o)

SORT_NAME     = push_swap

LIBFT_NAME      = libft.a

CC              = cc

RM              = rm -f

CFLAGS = -Wall -Wextra -Werror


all:            $(LIBFT_NAME) $(SORT_NAME)

$(LIBFT_NAME):
	$(MAKE) all -C ./libft/source

$(SORT_NAME): $(OBJS)
	$(CC) -o $(SORT_NAME) $(CFLAGS) $(OBJS) ./libft/source/libft.a

clean:
	$(MAKE) clean -C ./libft/source
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft/source
	$(RM) $(SORT_NAME)

re: fclean all

.PHONY: all clean fclean re client server
