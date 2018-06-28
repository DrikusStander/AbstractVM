#include "parse.hpp"

void	parse_assert(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 2 && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle assert command here
			std::cout << "ASSERT - "<< words[0] << std::endl;
			if (the_stack->getTopOfStack()->val->getType() == get_type(words[1]) )
			{
				std::size_t pos_s = words[1].find("(");
				std::size_t pos_e = words[1].find(")");
				std::string str = words[1].substr(pos_s + 1,  pos_e - pos_s - 1);
				if (the_stack->getTopOfStack()->val->toString() != str)
				{
					throw Stack_error("Assert value and value on top of the stack do not match");
				}
			}
			else
			{
				throw Stack_error("Assert value and value on top of the stack do not match");
			}
		}
	}
	else if (words.size() > 2 && words[2][0] == ';' && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle assert command here
			std::cout << "comment - " << words[0] << std::endl;
			if (the_stack->getTopOfStack()->val->getType() == get_type(words[1]) )
			{
				std::size_t pos_s = words[1].find("(");
				std::size_t pos_e = words[1].find(")");
				std::string str = words[1].substr(pos_s + 1,  pos_e - pos_s - 1);
				if (the_stack->getTopOfStack()->val->toString() != str)
				{
					throw Stack_error("Assert value and value on top of the stack do not match");
				}
			}
			else
			{
				throw Stack_error("Assert value and value on top of the stack do not match");
			}
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}