
#include "main.hpp"


int		main(int ac, char **av)
{
	if (ac != 2)
	{
		return(0);
	}
	else
	{
		readFile(av[1]);
	}
	return(0);
}