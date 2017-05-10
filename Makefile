CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

SRC = my_malloc.c slist.c get_next_line.c ft.c ilist.c parse_line.c \
		load_file.c coordinates.c hooks.c colors.c draw_lines.c draw.c \
		init.c cleanup.c main.c
OBJ = $(SRC:.c=.o)

all: minilibX/libmlx.a $(NAME)

libft/libmlx.a:
	make -C minilibX

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ -LminilibX -lmlx -lm \
		-framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -c $^ $(CFLAGS) -Ilibft/includes -IminilibX

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette *.h $(SRC)
