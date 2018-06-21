#include "parse.hpp"

bool	check_args(std::string word)
{
	if (std::regex_match(word, std::regex("([a-z]{3}[0-9]{2}\\()([0-9]+\\))")) || std::regex_match(word, std::regex("([a-z]+\\()([0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	return(false);
}

void	parse_push(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 2 && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle push command here
			std::cout << "PUSH - "<< words[0] << std::endl;
		}
	}
	else if (words.size() > 2 && words[2][0] == ';' && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle push command here
			std::cout << "comment - " << words[0] << std::endl;
		}
	}
	else
		errors << "Invalid Command on line " << line_nr << std::endl;
}