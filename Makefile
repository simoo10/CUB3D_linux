CC      = cc
CFLAGS	= -Wall -Wextra -Werror#-fsanitize=address
LIBC	= ar -rc
RM		= rm -f
NAME	= cub3D
MLX		= minilibx-linux
SRC		= main.c\
			libft_utils/get_next_line.c\
			libft_utils/get_next_line_utils.c\
			libft_utils/libft_utils.c\
			map_check.c\
			fill_map.c\
			textures_check.c\
			error.c\
			draw.c\
			rgb_check.c\
			struct_init.c\
			check_utils.c\
			move.c\
			2d_casting.c\
			3d_casting.c\
			3d_casting_utils.c\
			textures.c\
			textures2.c\
			fill_map_utils.c\
			check_utils2.c\
			libft_utils/libft_utils2.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -g3 -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC)  $(OBJ)   -lm -lmlx -lXext -lX11 -o $(NAME) 

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all