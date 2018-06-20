
#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>


void						readFile(std::string fileName);
std::string					trim(std::string &str);
std::vector<std::string>	strsplit(std::string &line, char delem);

#endif