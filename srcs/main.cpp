
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
		catch(Stack_error &exception)
		{
			std::cout << "Stack Exceptions :\n" << exception.what();
		}
		catch(DivByZero_error &exception)
		{
			std::cout << "Division Exceptions :\n" << exception.what();
		}
		catch(OverFlow_error &exception)
		{
			std::cout << "OverFlow Exceptions :\n" << exception.what();
		}
		return(0);
	}
	else
	{
		// int val1 = 3;
		// int val2 = 2;
		
		(void)av;
		try
		{
			readFile(av[1]);
			
			Stack the_stak;
			Factory fac;

			t_stack *item1 = new t_stack;
			item1->next = NULL;
			item1->val = fac.createOperand(eOperandType::int8, "102");

			t_stack *item2 = new t_stack;
			item2->next = NULL;
			std::stringstream ss;
			ss << LONG_MIN;
			std::string str = ss.str();

			item2->val = fac.createOperand(eOperandType::int8, "3");

			the_stak.addToStack(item1);
			the_stak.dumpStack();
			std::cout << "****************" << std::endl;
			the_stak.addToStack(item2);
			the_stak.dumpStack();

			std::cout << "<><><><><><><><><>><><><><><><><><><>><><><>"  << std::endl;
		
			t_stack *item5 = new t_stack;
			item5->next = NULL;
			item5->val = static_cast<Int8Operand const &>(*(item1->val)) + *(item2->val);
			std::cout << "<><><><><><><><><>><><><><><><><><><>><><><>"  << std::endl;
			the_stak.addToStack(item5);
			the_stak.dumpStack();

			t_stack *item6 = new t_stack;
			item6->next = NULL;
			item6->val = static_cast<Int8Operand const &>(*(item1->val)) - *(item2->val);
			std::cout << "<><><><><><><><><>><><><><><><><><><>><><><>"  << std::endl;
			the_stak.addToStack(item6);
			the_stak.dumpStack();


			std::cout << "int8 max " << INT8_MAX << "int8 min " << INT8_MIN << "int16 max " << INT16_MAX << "int16 min " << INT16_MIN << "int32 max " << INT32_MAX << "int32 min " << INT32_MIN << std::endl;


			// item1->val.in32 = val1;
			// t_stack *item2 = new t_stack;
			// item2->next = NULL;
			// item2->val.in32 = val2;
			
			// the_stak.removeFromStack();
			// the_stak.dumpStack();
			// the_stak.removeFromStack();
			// the_stak.removeFromStack();
			the_stak.removeFromStack();
			the_stak.removeFromStack();
			the_stak.removeFromStack();
			the_stak.removeFromStack();


		}
		catch(Lexical_error &exception)
		{
			std::cout << "Lexical/Syntax Exceptions :\n" << exception.what();
		}
		catch(Stack_error &exception)
		{
			std::cout << "Stack Exceptions :\n" << exception.what();
		}
		catch(DivByZero_error &exception)
		{
			std::cout << "Division Exceptions :\n" << exception.what();
		}
		catch(OverFlow_error &exception)
		{
			std::cout << "OverFlow Exceptions :\n" << exception.what();
		}
	}
	return(0);
}