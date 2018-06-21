#include "parse.hpp"
#include "Exceptions.hpp"
bool FILE_CHECKED = false;

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

void	readFile_1(std::string fileName)
{
	std::ifstream ifs;
	std::string line;
	std::vector<std::string> words;
	std::stringstream errors;
	int line_nr = 1;
	
	read_file:
	ifs.open(fileName, std::ifstream::in);
	while (getline(ifs, line))
	{
		words.clear();
		if (line.size() != 0)
			words = strsplit(line, ' ');
		if (words.size() != 0)
		{
			if (words[0][0] == ';')
				goto contin;
			else if (words[0] == "push")
				parse_push(words, line_nr, errors);
			else if (words[0] == "add")
				parse_add(words, line_nr, errors);
			else if (words[0] == "sub")
				parse_sub(words, line_nr, errors);
			else if (words[0] == "mul")
				parse_mul(words, line_nr, errors);
			else if (words[0] == "div")
				parse_div(words, line_nr, errors);
			else if (words[0] == "mod")
				parse_mod(words, line_nr, errors);
			else if (words[0] == "assert")
				parse_assert(words, line_nr, errors);
			else if (words[0] == "pop")
				parse_pop(words, line_nr, errors);
			else if (words[0] == "dump")
				parse_dump(words, line_nr, errors);
			else if (words[0] == "print")
				parse_print(words, line_nr, errors);
			else if (words[0] == "exit")
				parse_exit(words, line_nr, errors);
			else
				errors << "Invalid Command on line " << line_nr << std::endl;
		}
		contin:
		line_nr++;
	}
	ifs.close();
	if (!errors.str().empty())
	{
		throw Lexical_error(errors.str());
	}
	else if (FILE_CHECKED == false)
	{
		FILE_CHECKED = true;
		goto read_file;
	}
}