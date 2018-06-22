#include "parse.hpp"

void	parse_add(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			// handle add here
			std::cout << "ADD - " << words[0] << std::endl;
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			// handle add here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}