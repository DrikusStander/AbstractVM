#include "parse.hpp"

void	parse_exit(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 1)
	{
		EXIT = true;
		if (FILE_CHECKED)
		{
			// handle exit here
			std::cout << "EXIT - " << words[0] << std::endl;
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		EXIT = true;
		if (FILE_CHECKED)
		{
			// handle exit here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}