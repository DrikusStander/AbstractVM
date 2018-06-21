
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <iostream>
#include <exception>

class Lexical_error : public std::exception
{
	private:
		std::string _error;
	public:
		Lexical_error( std::string error);
		~Lexical_error( void ) throw();
		const char* what() const throw();
};

#endif
