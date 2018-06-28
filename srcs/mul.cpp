#include "parse.hpp"

void	parse_mul(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			if (the_stack->getStackSize() < 2)
			{
				throw Stack_error("Stack size to small for MUL");
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			result->val = *(the_stack->getTopOfStack()->val) * *(the_stack->getSecondItemOfStack()->val);
			std::cout << "============================================ result " << result->val->toString() << std::endl;
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
				throw Stack_error("Stack size to small for MUL");
			}
			t_stack *result = new t_stack;
			result->next = NULL;
			std::cout << "here" << std::endl;
			if (dynamic_cast<const floatOperand *>( the_stack->getTopOfStack()->val ) || dynamic_cast<const doubleOperand *>( the_stack->getTopOfStack()->val ) )
			{
				std::cout << "here here" << std::endl;

				result->val = reinterpret_cast<const doubleOperand &>(*(the_stack->getTopOfStack()->val)) * *(the_stack->getSecondItemOfStack()->val);
			}
			else
			{
				std::cout << "here here here" << std::endl;
				result->val = reinterpret_cast<const Int32Operand &>(the_stack->getTopOfStack()->val) * *(the_stack->getSecondItemOfStack()->val);
			}
			std::cout << "here" << std::endl;
			//std::cout << "============================================ result " << result->val->getType() << std::endl;
			the_stack->removeFromStack();
			the_stack->removeFromStack();
			the_stack->addToStack(result);
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}