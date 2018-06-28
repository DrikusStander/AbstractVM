#include "parse.hpp"

void	parse_exit(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		EXIT = true;
		if (FILE_CHECKED)
		{
			int i = the_stack->getStackSize();
			while (i > 0)
			{
				the_stack->removeFromStack();
				i--;
			}
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		EXIT = true;
		if (FILE_CHECKED)
		{
			int i = the_stack->getStackSize();
			while (i > 0)
			{
				the_stack->removeFromStack();
				i--;
			}
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}