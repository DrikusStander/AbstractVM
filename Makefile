FLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp parse.cpp Stack.cpp Exceptions.cpp push.cpp add.cpp sub.cpp mul.cpp div.cpp mod.cpp pop.cpp dump.cpp print.cpp assert.cpp exit.cpp
NAME = AbstractVM

all:
	clang++ $(SRCS) $(FLAGS) -o $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean

re: fclean all