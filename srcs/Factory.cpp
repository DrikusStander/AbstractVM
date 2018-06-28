
#include "Factory.hpp"

Factory::Factory( void )
{
	return;
}

Factory::~Factory( void )
{
	return;
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
	std::cout << "creating INT8 object" << std::endl;
	eOperandType temp = int8;
	return(new Int8Operand(temp, value));
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
	std::cout << "creating INT16 object" << std::endl;

	eOperandType temp = int16;
	return(new Int16Operand(temp, value));
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
	std::cout << "creating INT32 object" << std::endl;

	eOperandType temp = int32;
	return(new Int32Operand(temp, value));
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
	std::cout << "creating float object" << std::endl;

	eOperandType temp = Float;
	return(new floatOperand(temp, value));
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
	std::cout << "creating Double object" << std::endl;

	eOperandType temp = Double;
	return(new doubleOperand(temp, value));
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	return( ( this->*funcs[ type ] )( value ) );
}

Factory::fn Factory::funcs[] = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};