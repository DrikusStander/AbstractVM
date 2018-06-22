FLAGS = -Wall -Werror -Wextra -Iincludes -std=c++11
DIR = ./srcs/
SRCS = main.cpp parse.cpp Stack.cpp Exceptions.cpp push.cpp add.cpp sub.cpp mul.cpp div.cpp mod.cpp pop.cpp dump.cpp print.cpp assert.cpp exit.cpp Factory.cpp IOperand.cpp Int32Operand.cpp
NAME = AbstractVM

all:
	clang++ $(addprefix $(DIR), $(SRCS)) $(FLAGS) -o $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean
	rm -fr stdin

re: fclean all