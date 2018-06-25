
#include "IOperand.hpp"

Int16Operand::Int16Operand( void )
{
	return;
}

Int16Operand::Int16Operand( eOperandType & type, std::string const &val)
{
	// std::cout << "Int16Operand constructor val str: " << val << std::endl;	
	this->_type = type;
	this->_val.in16 = std::atoi(val.c_str());
	// std::cout << "Int16Operand constructor atoi: " << std::atoi(val.c_str()) << std::endl;	
	// std::cout << "Int16Operand constructor type: "<< this->_type << " value : " << this->_val.in16 << std::endl;
	return;
}

Int16Operand::Int16Operand(Int16Operand const & src)
{
	this->_val.in16 = src._val.in16;
	this->_type = src._type;
	return;
}

Int16Operand const & Int16Operand::operator=(Int16Operand const & rhs)
{
	this->_val = rhs._val;
	this->_type = rhs._type;
	return(*this);
}

int Int16Operand::getPrecision( void ) const
{
	return(this->_type);
}

eOperandType Int16Operand::getType( void ) const
{
	return(this->_type);
}

IOperand const * Int16Operand::operator+( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) + ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) + ptr->getVal();
		}
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val >= -FLT_MAX)
		{
			type = Float;
			return(new floatOperand(type, str));
		}
		else
		{
			type = Double;
			return(new doubleOperand(type, str));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		int val = this->_val.in16 + ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		// if (val <= INT8_MAX && val >= INT8_MIN)
		// {
		// 	type = int8;
		// 	return(new Int16Operand(type, str));
		// }
		if (val <= INT16_MAX && val >= INT16_MIN )
		{
			type = int16;
			return(new Int16Operand(type, str));
		}
		else
		{
			type = int32;
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

IOperand const * Int16Operand::operator-( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) - ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) - ptr->getVal();
		}
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val >= -FLT_MAX)
		{
			type = Float;
			return(new floatOperand(type, str));
		}
		else
		{
			type = Double;
			return(new doubleOperand(type, str));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		int val = this->_val.in16 - ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		// if (val <= INT8_MAX && val >= INT8_MIN)
		// {
		// 	type = int8;
		// 	return(new Int16Operand(type, str));
		// }
		if (val <= INT16_MAX && val >= INT16_MIN )
		{
			type = int16;
			return(new Int16Operand(type, str));
		}
		else
		{
			type = int32;
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

IOperand const * Int16Operand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) * ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			val = static_cast<double>(this->_val.in16) * ptr->getVal();
		}
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val >= -FLT_MAX)
		{
			type = Float;
			return(new floatOperand(type, str));
		}
		else
		{
			type = Double;
			return(new doubleOperand(type, str));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		int val = this->_val.in16 * ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		// if (val <= INT8_MAX && val >= INT8_MIN)
		// {
		// 	type = int8;
		// 	return(new Int16Operand(type, str));
		// }
		if (val <= INT16_MAX && val >= INT16_MIN )
		{
			type = int16;
			return(new Int16Operand(type, str));
		}
		else
		{
			type = int32;
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

IOperand const * Int16Operand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->_val.in16) / ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->_val.in16) * ptr->getVal();
		}
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val >= -FLT_MAX)
		{
			type = Float;
			return(new floatOperand(type, str));
		}
		else
		{
			type = Double;
			return(new doubleOperand(type, str));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
		int val = this->_val.in16 / ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		// if (val <= INT8_MAX && val >= INT8_MIN)
		// {
		// 	type = int8;
		// 	return(new Int16Operand(type, str));
		// }
		if (val <= INT16_MAX && val >= INT16_MIN )
		{
			type = int16;
			return(new Int16Operand(type, str));
		}
		else
		{
			type = int32;
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

IOperand const * Int16Operand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->_val.in16), ptr->getVal());
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->_val.in16), ptr->getVal());
		}
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val >= -FLT_MAX)
		{
			type = Float;
			return(new floatOperand(type, str));
		}
		else
		{
			type = Double;
			return(new doubleOperand(type, str));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
		int val = this->_val.in16 % ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		// if (val <= INT8_MAX && val >= INT8_MIN)
		// {
		// 	type = int8;
		// 	return(new Int8Operand(type, str));
		// }
		if (val <= INT16_MAX && val >= INT16_MIN )
		{
			type = int16;
			return(new Int16Operand(type, str));
		}
		else
		{
			type = int32;
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

std::string const & Int16Operand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.in16; // should change to in16 as to just display the ascii charachters
	std::string *sstr = new std::string(str.str());
	return(*sstr);
}

Int16Operand::~Int16Operand( void )
{
	return;
}

int16_t	Int16Operand::getVal( void ) const
{
	return(this->_val.in16);
}