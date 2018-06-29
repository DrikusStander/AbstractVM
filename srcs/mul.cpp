#include "parse.hpp"

void	parse_mul(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() < 2)
			{
				std::stringstream str;
				str << "Stack size to small for MUL, Line: " << line_nr;
				throw Stack_error(str.str());
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			result->val = *(the_stack->getTopOfStack()->val) * *(the_stack->getSecondItemOfStack()->val);
			if (VERBOSE == true)
			{
				std::stringstream str;
				std::cout << blue << the_stack->getTopOfStack()->val->toString() << " * " << the_stack->getSecondItemOfStack()->val->toString() << normal << std::endl;
			}
			the_stack->removeFromStack();
			the_stack->removeFromStack();
			the_stack->addToStack(result);
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() < 2)
			{
				std::stringstream str;
				str << "Stack size to small for MUL, Line: " << line_nr;
				throw Stack_error(str.str());
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			result->val = *(the_stack->getTopOfStack()->val) * *(the_stack->getSecondItemOfStack()->val);
			if (VERBOSE == true)
			{
				std::stringstream str;
				std::cout << blue << the_stack->getTopOfStack()->val->toString() << " * " << the_stack->getSecondItemOfStack()->val->toString() << normal << std::endl;
			}
			the_stack->removeFromStack();
			the_stack->removeFromStack();
			the_stack->addToStack(result);
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}