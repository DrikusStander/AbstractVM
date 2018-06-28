#include "parse.hpp"

void	parse_add(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() < 2)
			{
				throw Stack_error("Stack size to small for ADD");
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			result->val = *(the_stack->getTopOfStack()->val) + *(the_stack->getSecondItemOfStack()->val);
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
				throw Stack_error("Stack size to small for ADD");
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			result->val = *(the_stack->getTopOfStack()->val) + *(the_stack->getSecondItemOfStack()->val);
			the_stack->removeFromStack();
			the_stack->removeFromStack();
			the_stack->addToStack(result);
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}