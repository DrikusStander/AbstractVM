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


Stack_error::Stack_error( std::string error) : _error(error)
{
	return;
}
 
Stack_error::~Stack_error( void ) throw()
{
	return;
}

const char* Stack_error::what() const throw() 
{
	return(this->_error.c_str());
}


DivByZero_error::DivByZero_error( std::string error) : _error(error)
{
	return;
}
 
DivByZero_error::~DivByZero_error( void ) throw()
{
	return;
}

const char* DivByZero_error::what() const throw() 
{
	return(this->_error.c_str());
}

OverFlow_error::OverFlow_error( std::string error) : _error(error)
{
	return;
}
 
OverFlow_error::~OverFlow_error( void ) throw()
{
	return;
}

const char* OverFlow_error::what() const throw() 
{
	return(this->_error.c_str());
}