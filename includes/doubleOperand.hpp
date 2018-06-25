

#ifndef doubleOperand_HPP
#define doubleOperand_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>


class doubleOperand : public IOperand
{
	private:
		store			_val;
		eOperandType	_type;
	protected:
		doubleOperand( void );
	public:
		doubleOperand( eOperandType & type, std::string const & val);
		doubleOperand( doubleOperand const & src );
		doubleOperand const & operator=(doubleOperand const & rhs);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const;
		virtual ~doubleOperand( void );
		double	getVal( void ) const;
		IOperand *next;
};

#endif