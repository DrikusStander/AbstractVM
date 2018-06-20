FLAGS = -Wall -Werror -Wextra
SRCS = main.cpp parse.cpp
NAME = AbstractVM

all:
	clang++ $(SRCS) $(FLAGS) -o $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean

re: fclean all