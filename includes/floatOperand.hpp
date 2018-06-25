

#ifndef floatOperand_HPP
#define floatOperand_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>


class floatOperand : public IOperand
{
	private:
		store			_val;
		eOperandType	_type;
	protected:
		floatOperand( void );
	public:
		floatOperand( eOperandType & type, std::string const & val);
		floatOperand( floatOperand const & src );
		floatOperand const & operator=(floatOperand const & rhs);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const;
		virtual ~floatOperand( void );
		float	getVal( void ) const;
		IOperand *next;
};

#endif