#include "Exceptions.hpp"

Lexical_error::Lexical_error( std::string error) : _error(error)
{
	return;
}
 
Lexical_error::~Lexical_error( void ) throw()
{
	return;
}

const char* Lexical_error::what() const throw() 
{
	return(this->_error.c_str());
}