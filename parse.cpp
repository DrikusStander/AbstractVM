#include "parse.hpp"


std::string trim(std::string &str)
{
	const char *white_space = " \n\t\r\f\v";

	str.erase(0, str.find_first_not_of(white_space));
	str.erase(str.find_last_not_of(white_space) + 1, str.length());
	return(str);
}

std::vector<std::string>	strsplit(std::string &line, char delem)
{
	std::string			word;
	std::vector<std::string>	words;

	std::stringstream tokenStream(line);
	while (getline(tokenStream, word, delem))
	{
		word = trim(word);
		if (word.size() != 0)
		{
			words.push_back(word);
		}
	}
	return (words);
}

void	readFile(std::string fileName)
{
	std::ifstream ifs;
	std::string line;
	std::vector<std::string> words;

	ifs.open(fileName, std::ifstream::in);
	while (getline(ifs, line))
	{
		words.clear();
		if (line.size() != 0) 
		{
			words = strsplit(line, ' ');
		}
		if (words.size() != 0)
		{
			if (words[0][0] == ';')
			{
				std::cout << "comment - " << words[0] << std::endl;
				continue;
			}
			else if (words[0] == "push")
			{
				if (words.size() == 2)
					std::cout << "PUSH - "<< words[0] << std::endl;
				else if (words[2][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "add")
			{
				if (words.size() == 1)
					std::cout << "ADD - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "sub")
			{
				if (words.size() == 1)
					std::cout << "SUB - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "mul")
			{
				if (words.size() == 1)
					std::cout << "MUL - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "div")
			{
				if (words.size() == 1)
					std::cout << "DIV - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "mod")
			{
				if (words.size() == 1)
					std::cout << "MOD - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "assert")
			{
				if (words.size() == 2)
					std::cout << "ASSERT - " << words[0] << std::endl;
				else if (words[2][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "pop")
			{
				if (words.size() == 1)
					std::cout << "POP - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "dump")
			{
				if (words.size() == 1)
					std::cout << "DUMP - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "print")
			{
				if (words.size() == 1)
					std::cout << "PRINT - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else if (words[0] == "exit")
			{
				if (words.size() == 1)
					std::cout << "EXIT - " << words[0] << std::endl;
				else if (words[1][0] == ';')
				{
					std::cout << "comment - " << words[0] << std::endl;
				}
				else
				{
					std::cout << "Invalid Command" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid Command" << std::endl;
			}
		}	
	}
	ifs.close();
}