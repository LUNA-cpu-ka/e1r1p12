SRC = validation.c error.c mlx.c\
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
GFLAGS = -Wall -Wextra -Werror 
NAME = so_long
LIBFT = libft.a

all: $(NAME)
///remove this 10 (%.o: %.c) from your makefile 
%.o: %.c
	@cc $(GFLAGS) -c $< -o $@
	@cc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME)	: $(OBJ) $(LIBFT)
	@echo "making $(NAME)"
	@cc $(OBJ) $(LIBFT) -fsanitize=address -g -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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