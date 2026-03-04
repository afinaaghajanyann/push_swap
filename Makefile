NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = s_func.c push_swap.c \

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all