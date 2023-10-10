NAME			= fractol
SRCS			= main.c string.c start.c fractal.c \

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -Iminilibx -g3 -fsanitize=address
FFLAGS			= -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): minilibx
	$(CC) $(CFLAGS) $(SRCS) $(FFLAGS) minilibx_macos/libmlx.a -o $(NAME)

minilibx:
	cd minilibx_macos && make
clean:
	$(RM)

fclean:	clean
	$(RM) $(NAME)
	cd minilibx_macos && make clean

re:	fclean $(NAME)

.PHONY:	all clean fclean re minilibx