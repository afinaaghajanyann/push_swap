NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	basic.c     ft_itoa.c	lists.c   p_funcs.c    ret_reminder.c \
		chunk.c     ft_split.c	main.c  r_funcs.c \
		custom.c    helper1.c  rr_funcs.c \
		fill_arr.c  helper2.c	pars.c	  radix.c      s_funcs.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all  re