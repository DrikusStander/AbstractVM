#include "parse.hpp"

void	parse_print(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() > 0)
			{
				if (the_stack->getTopOfStack()->val->getType() == eOperandType::int8)
				{
					const Int8Operand *val = reinterpret_cast<const Int8Operand *>(the_stack->getTopOfStack()->val);
					val->putChar();
				}
				else
				{
					std::stringstream str;
					str << "Value on top of the stack is not of type INT8, can not PRINT, Line: " << line_nr;
					throw Stack_error(str.str());
				}
			}
			else
			{
				std::stringstream str;
				str << "Stack is empty, can not PRINT, Line: " << line_nr;
				throw Stack_error(str.str());
			}
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() > 0)
			{
				if (the_stack->getTopOfStack()->val->getType() == eOperandType::int8)
				{
					const Int8Operand *val = reinterpret_cast<const Int8Operand *>(the_stack->getTopOfStack()->val);
					val->putChar();
				}
				else
				{
					std::stringstream str;
					str << "Value on top of the stack is not of type INT8, can not PRINT, Line: " << line_nr;
					throw Stack_error(str.str());
				}
			}
			else
			{
				std::stringstream str;
				str << "Stack is empty, can not PRINT, Line: " << line_nr;
				throw Stack_error(str.str());
			}
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}