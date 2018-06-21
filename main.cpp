
#include "main.hpp"


int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::string line;
		std::ofstream ofs("stdin");
		do 
		{
			std::getline(std::cin, line);
			ofs << line << std::endl;
		}
		while (line != ";;");
		ofs.close();
		try
		{
			readFile("stdin");
		}
		catch(Lexical_error &exception)
		{
			std::cout << "Lexical/Syntax Exceptions :\n" << exception.what();
		}
		return(0);
	}
	else
	{
		int val1 = 3;
		int val2 = 2;
		
		(void)av;
		try
		{
			readFile(av[1]);
		}
		catch(Lexical_error &exception)
		{
			std::cout << "Lexical/Syntax Exceptions :\n" << exception.what();
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