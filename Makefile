NAME			= fractol
SRCS			= main.c string.c start.c math.c draw.c hooks.c\

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -Iminilibx -g3 -fsanitize=address
FFLAGS			= -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): minilibx
	$(CC) $(CFLAGS) $(SRCS) $(FFLAGS) minilibx/libmlx.a -o $(NAME)

minilibx:
	cd minilibx && make
clean:
	$(RM)

fclean:	clean
	$(RM) $(NAME)
	cd minilibx && make clean

re:	fclean $(NAME)

.PHONY:	all clean fclean re minilibx