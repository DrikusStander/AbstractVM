
#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>
#include <cmath>
#include "Exceptions.hpp"


enum eOperandType
{
	int8 = 0,
	int16,
	int32,
	Float,
	Double
};

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0;								// Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0;							// Type of the instance
		virtual IOperand const * operator+( IOperand const & rhs ) const = 0;	// Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0;	// Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0;	// Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0;	// Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0;	// Modulo
		virtual std::string const & toString( void ) const = 0; 				// String representation of the instance
		virtual ~IOperand( void ) {}
};

union store
{
	std::int8_t in8;
	std::int16_t in16;
	std::int32_t in32;
	float fl;
	double dl;
};

#include "Int32Operand.hpp"
#include "Int16Operand.hpp"
#include "doubleOperand.hpp"
#include "floatOperand.hpp"



class Int8Operand : public IOperand
{
	private:
		store			_val;
		eOperandType	_type;
	protected:
		Int8Operand( void );
	public:
		Int8Operand( eOperandType & type, std::string const & val);
		Int8Operand( Int8Operand const & src );
		Int8Operand const & operator=(Int8Operand const & rhs);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const;
		virtual ~Int8Operand( void );
		int8_t	getVal( void ) const;
		IOperand *next;
};

#endif