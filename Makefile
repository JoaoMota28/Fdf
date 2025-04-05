NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/
MLX = minilibx-linux

SRCS = fdf.c init.c utils.c parse.c pixel.c line.c free.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@make -C $(MLX)
	@$(CC) $(CFLAGS) -I $(LIBFT) -I $(MLX) -L $(LIBFT) -L $(MLX) $(OBJS) -o $(NAME) -lft -lmlx -lXext -lX11 -lm

clean:
	@make -s -C $(LIBFT) clean
	@make -s -C $(MLX) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -s -C $(LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re