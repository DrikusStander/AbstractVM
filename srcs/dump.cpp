#include "parse.hpp"

void	parse_dump(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			the_stack->dumpStack();
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			the_stack->dumpStack();

		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}