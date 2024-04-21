SRC = validation.c error.c mlx.c main.c read_map.c dimention_counter.c\
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror 
NAME = so_long
LIBFT = libft.a

all: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT)
	@echo "making $(NAME)"
	@cc $(OBJ) $(LIBFT) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@echo "making libft.."
	@make -C libft
	@mv libft/libft.a .

clean:
	@echo "cleaning.."
	@rm -f $(OBJ) 
	@make -C libft clean
	@rm -fr $(LIBFT)

fclean: clean
	@echo "full cleaning.. "
	@rm -f $(NAME)

re: fclean all

.SILENT: re clean fclean