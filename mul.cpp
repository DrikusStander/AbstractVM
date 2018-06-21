#include "parse.hpp"

void	parse_mul(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 1)
	{
		if (FILE_CHECKED)
		{
			// handle mul here
			std::cout << "MUL - " << words[0] << std::endl;
		}
	}
	else if (words.size() > 1 && words[1][0] == ';')
	{
		if (FILE_CHECKED)
		{
			// handle mul here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Invalid Command on line " << line_nr << std::endl;
}