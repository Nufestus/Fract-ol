
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = 	ft_printhexup.c ft_printptr.c ft_printunbr.c ft_printf.c \
		ft_printhexlow.c ft_printnbr.c ft_printstr.c ft_putchar.c \
		ft_converthex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all