#include "parse.hpp"

void	parse_print(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			// handle print here
			std::cout << "PRINT - " << words[0] << std::endl;
			if (the_stack->getTopOfStack()->val->getType() == eOperandType::int8)
			{
				const Int8Operand *val = reinterpret_cast<const Int8Operand *>(the_stack->getTopOfStack()->val);
				val->putChar();
			}
			else
			{
				throw Stack_error("Value on top of the stack is not of type INT8");
			}
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			// handle print here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}