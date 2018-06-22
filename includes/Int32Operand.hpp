

#ifndef INT32OPERAND_HPP
#define INT32OPERAND_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>


class Int32Operand : public IOperand
{
	private:
		store			_val;
		eOperandType	_type;
	protected:
		Int32Operand( void );
	public:
		Int32Operand( eOperandType & type, std::string const & val);
		Int32Operand( Int32Operand const & src );
		Int32Operand const & operator=(Int32Operand const & rhs);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const;
		virtual ~Int32Operand( void );
		int32_t	getVal( void ) const;
		IOperand *next;
};

#endif