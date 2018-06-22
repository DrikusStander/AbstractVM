
#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "IOperand.hpp"
#include "Int32Operand.hpp"

class Factory
{
	private:
		typedef IOperand const * (Factory::*fn)(std::string const &) const;
		static fn funcs[];
	protected:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
	public:
		Factory( void );
		~Factory( void );
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};
#endif