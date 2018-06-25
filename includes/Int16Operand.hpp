

#ifndef Int16Operand_HPP
#define Int16Operand_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>


class Int16Operand : public IOperand
{
	private:
		store			_val;
		eOperandType	_type;
	protected:
		Int16Operand( void );
	public:
		Int16Operand( eOperandType & type, std::string const & val);
		Int16Operand( Int16Operand const & src );
		Int16Operand const & operator=(Int16Operand const & rhs);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const;
		virtual ~Int16Operand( void );
		int16_t	getVal( void ) const;
		IOperand *next;
};

#endif