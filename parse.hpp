
#ifndef	PARSE_HPP
#define	PARSE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

extern bool FILE_CHECKED;

/*
	parse.cpp
*/
void						readFile_1(std::string fileName);
std::string					trim(std::string &str);
std::vector<std::string>	strsplit(std::string &line, char delem);

/*
	push.cpp
*/
void						parse_push(std::vector<std::string> &words, int line_nr, std::stringstream &errors);
bool						check_args(std::string word);

/*
	add.cpp
*/
void						parse_add(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	sub.cpp
*/
void						parse_sub(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	mul.cpp
*/
void						parse_mul(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	div.cpp
*/
void						parse_div(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	mod.cpp
*/
void						parse_mod(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	pop.cpp
*/
void						parse_pop(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	dump.cpp
*/
void						parse_dump(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	print.cpp
*/
void						parse_print(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	exit.cpp
*/
void						parse_exit(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

/*
	assert.cpp
*/
void						parse_assert(std::vector<std::string> &words, int line_nr, std::stringstream &errors);

#endif