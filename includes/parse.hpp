
#ifndef	PARSE_HPP
#define	PARSE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "Stack.hpp"

extern bool FILE_CHECKED;
extern bool EXIT;
extern bool VERBOSE;
extern char red[];
extern char blue[];
extern char green[];
extern char normal[];



/*
	parse.cpp
*/
void						readFile(std::string fileName);
std::string					trim(std::string &str);
std::vector<std::string>	strsplit(std::string &line, char delem);

/*
	push.cpp
*/
void						parse_push(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);
bool						check_args(std::string word);
eOperandType				get_type(std::string word);

/*
	add.cpp
*/
void						parse_add(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	sub.cpp
*/
void						parse_sub(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	mul.cpp
*/
void						parse_mul(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	div.cpp
*/
void						parse_div(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	mod.cpp
*/
void						parse_mod(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	pop.cpp
*/
void						parse_pop(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	dump.cpp
*/
void						parse_dump(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	print.cpp
*/
void						parse_print(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	exit.cpp
*/
void						parse_exit(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

/*
	assert.cpp
*/
void						parse_assert(std::vector<std::string> &words, int line_nr, std::stringstream &errors, Stack *the_stack);

#endif