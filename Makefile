NAME = fillit
SRC = {main.c,solve.c,solve_func.c,validate_file.c}

all : $(NAME)

$(NAME):
	$(CC) $(SRC) libft.a -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all
