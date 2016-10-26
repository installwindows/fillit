NAME = fillit
SRC = {main.c,gg.c,solve.c,solve_func.c,validate_file.c}
CFLAGS = -Wall -Werror -Wextra
all : $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft

clean:

fclean:
	rm $(NAME)

re: fclean all
