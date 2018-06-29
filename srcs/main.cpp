
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
			std::cout << red << "Lexical/Syntax Exceptions :\n" << exception.what() << normal;
		}
		catch(Stack_error &exception)
		{
			std::cout << red << "Stack Exceptions :\n" << exception.what() << normal;
		}
		catch(DivByZero_error &exception)
		{
			std::cout << red << "Division Exceptions :\n" << exception.what() << normal;
		}
		catch(OverFlow_error &exception)
		{
			std::cout << red << "OverFlow Exceptions :\n" << exception.what() << normal;
		}
		return(0);
	}
	else
	{
		(void)av;
		try
		{
			readFile(av[1]);
		}
		catch(Lexical_error &exception)
		{
			std::cout << red << "Lexical/Syntax Exceptions :\n" << exception.what() << normal;
		}
		catch(Stack_error &exception)
		{
			std::cout << red << "Stack Exceptions :\n" << exception.what() << normal;
		}
		catch(DivByZero_error &exception)
		{
			std::cout << red << "Division Exceptions :\n" << exception.what() << normal;
		}
		catch(OverFlow_error &exception)
		{
			std::cout << red << "OverFlow Exceptions :\n" << exception.what() << normal;
		}
	}
	return(0);
}