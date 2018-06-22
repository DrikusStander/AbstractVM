#include "parse.hpp"

void	parse_assert(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 2 && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle assert command here
			std::cout << "ASSERT - "<< words[0] << std::endl;
		}
	}
	else if (words.size() > 2 && words[2][0] == ';' && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle assert command here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Syntax error on line " << line_nr << std::endl;
}