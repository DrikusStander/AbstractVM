#include "parse.hpp"

void	parse_pop(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() == 0)
			{
				throw Stack_error("Stack is empty cant POP");
			}
			the_stack->removeFromStack();
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() == 0)
			{
				throw Stack_error("Stack is empty cant POP");
			}
			the_stack->removeFromStack();
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}