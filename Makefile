NAME = fillit
SRC = {main.c,gg.c,solve.c,solve_func.c,validate_file.c}
CFLAGS = -Wall -Werror -Wextra
all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all
