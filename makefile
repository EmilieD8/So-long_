NAME	= so_long

MINILIBX_FLAGS = -Lmlx_linux -lmlx_Linux -L/user/lib -Imlx_linux -lXext -lX11 -lm -lz

HEADERS	:= -I ./include -I $(LIBMLX)/mlx.h

LIBS	:= ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a -Lmlx_Linux -lX11 -lXext -lm

PRINTF	:= ./Printf/libftprintf.a

SRCS =  so_long.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strlen.c \
		Check_map.c \
		so_long_utils.c \
		ft_initialize_graphics.c \
		render_images.c \
		ft_move.c

OBJS = $(SRCS:.c=.o)

CC 	= cc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

${NAME}: $(OBJS)
	@$(CC) $(SRCS) $(HEADERS) $(LIBS) $(PRINTF) $(CFLAGS) -o $(NAME)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
