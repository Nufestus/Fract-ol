CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX = ../minilibx/libmlx_Linux.a
PRINTF = ../ft_printf/libftprintf.a
NAME = fractol
SRCS = main.c ctrldata.c math_utils.c utils.c func.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -lXext -lX11 -lm $(MLX) $(PRINTF) -o $(NAME)

$(MLX):
	$(MAKE) -C ../minilibx

$(PRINTF):
	$(MAKE) -C ../ft_printf

%.o : %.c fractol.h ../ft_printf/ft_printf.h ../minilibx/mlx.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	$(MAKE) -C ../ft_printf clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C ../minilibx clean
	$(MAKE) -C ../ft_printf fclean

re : fclean all
