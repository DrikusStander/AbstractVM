#include "parse.hpp"

void	parse_div(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			// handle div here
			std::cout << "DIV - " << words[0] << std::endl;
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			// handle div here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Invalid Command on line " << line_nr << std::endl;
}