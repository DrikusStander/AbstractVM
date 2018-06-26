#include "parse.hpp"
#include "IOperand.hpp"

bool	check_args(std::string word)
{
	if (std::regex_match(word, std::regex("(double\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	else if (std::regex_match(word, std::regex("(float\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	else if (std::regex_match(word, std::regex("(int32\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	else if (std::regex_match(word, std::regex("(int16\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	else if (std::regex_match(word, std::regex("(int8\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(true);
	}
	return(false);
}

eOperandType	get_type(std::string word)
{
	if (std::regex_match(word, std::regex("(double\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(eOperandType::Double);
	}
	else if (std::regex_match(word, std::regex("(float\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(eOperandType::Float);
	}
	else if (std::regex_match(word, std::regex("(int32\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(eOperandType::int32);
	}
	else if (std::regex_match(word, std::regex("(int16\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(eOperandType::int16);
	}
	else if (std::regex_match(word, std::regex("(int8\\()((-|\\+)?[0-9]+(\\.?[0-9]+)?\\))")))
	{
		return(eOperandType::int8);
	}
	return(eOperandType::int8);
}



void	parse_push(std::vector<std::string> &words, int line_nr, std::stringstream &errors)
{
	if (words.size() == 2 && check_args(words[1]))
	{
		if (FILE_CHECKED)
		{
			// handle push command here
			std::cout << "PUSH - "<< words[0] << std::endl;
			std::size_t pos_s = words[1].find("(");
			std::size_t pos_e = words[1].find(")");
			std::cout << "sub string ---------------------------------------------------------------------------> " << words[1].substr(pos_s + 1,  pos_e - pos_s - 1) <<std::endl;
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
		errors << "Syntax error on line " << line_nr << std::endl;
}