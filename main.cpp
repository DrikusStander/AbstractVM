
#include "main.hpp"


int		main(int ac, char **av)
{
	if (ac != 2)
	{
		return(0);
	}
	else
	{
		int val1 = 3;
		int val2 = 2;
		
		(void)av;
		try
		{
			readFile_1(av[1]);
		}
		catch(Lexical_error &exception)
		{
			std::cout << "Lexical Exceptions :\n" << exception.what();
		}
		Stack the_stak;
		t_stack *item1 = new t_stack;
		item1->next = NULL;
		item1->val.in32 = val1;
		t_stack *item2 = new t_stack;
		item2->next = NULL;
		item2->val.in32 = val2;
		the_stak.addToStack(item1);
		the_stak.printStack();
		std::cout << "****************" << std::endl;
		the_stak.addToStack(item2);
		the_stak.printStack();
		the_stak.removeFromStack();
		the_stak.printStack();
	}
	return(0);
}