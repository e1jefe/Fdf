NAME = fdf

FILES = struct.c draw.c draw_line.c\
		keyhooks.c main.c point.c \
		points_rotation.c reader.c

OBJECTS = $(FILES:.c=.o)

LIBFT = libft/libft.a

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	gcc $(CFLAG) -c $< -o $@

$(NAME): $(LIBFT) $(OBJECTS)
	gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)

$(LIBFT):
	make -C libft/

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all

norme:
	norminette $(FILES)
