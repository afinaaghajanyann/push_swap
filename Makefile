NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	basic.c		ft_itoa.c	lists.c	p_funcs.c	ret_reminder.c \
		chunk.c		ft_split.c	main.c				r_funcs.c \
		custom.c	helper1.c	rr_funcs.c		helper3.c	main_funcs1.c\
		fill_arr.c	helper2.c	pars.c		radix.c	s_funcs.c	cleaning.c	smalls.c\
		counts.c	counts1.c	ft_printf.c

BONUS_SRCS = checker.c get_next_line.c get_next_line_utils.c \
			 checker_opers.c 

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

bonus/%.o: bonus/%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean fclean all  re bonus