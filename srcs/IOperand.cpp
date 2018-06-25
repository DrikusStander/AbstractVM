
#include "IOperand.hpp"

Int8Operand::Int8Operand( void )
{
	return;
}

Int8Operand::Int8Operand( eOperandType & type, std::string const &val)
{
	// std::cout << "Int8Operand constructor val str: " << val << std::endl;	
	this->_type = type;
	this->_val.in8 = std::atoi(val.c_str());
	// std::cout << "Int8Operand constructor atoi: " << std::atoi(val.c_str()) << std::endl;	
	// std::cout << "Int8Operand constructor type: "<< this->_type << " value : " << this->_val.in8 << std::endl;
	return;
}

Int8Operand::Int8Operand(Int8Operand const & src)
{
	this->_val.in8 = src._val.in8;
	this->_type = src._type;
	return;
}

Int8Operand const & Int8Operand::operator=(Int8Operand const & rhs)
{
	this->_val = rhs._val;
	this->_type = rhs._type;
	return(*this);
}

int Int8Operand::getPrecision( void ) const
{
	return(this->_type);
}

eOperandType Int8Operand::getType( void ) const
{
	return(this->_type);
}

IOperand const * Int8Operand::operator+( IOperand const & rhs ) const
{
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > FLT_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -FLT_MAX - this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			std::cout << "DBL_MAX : " << DBL_MAX << std::endl;
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		int val = this->getVal() + ptr->getVal();
		sstr << val;
		if (type == int8)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT8_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT8_MIN - this->getVal()))
				throw OverFlow_error("Int8 Overflow\n");
			return(new Int8Operand(type, sstr.str()));
		}
		else if (type == int16)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT16_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT16_MIN - this->getVal()))
				throw OverFlow_error("Int16 Overflow\n");
			return(new Int16Operand(type, sstr.str()));
		}
		else
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT32_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT32_MIN - this->getVal()))
				throw OverFlow_error("Int32 Overflow\n");
			return(new Int32Operand(type, sstr.str()));
		}
	}
	return(NULL);
}

IOperand const * Int8Operand::operator-( IOperand const & rhs ) const
{
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > FLT_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -FLT_MAX - this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			std::cout << "DBL_MAX : " << DBL_MAX << std::endl;
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		int val = this->getVal() + ptr->getVal();
		sstr << val;
		if (type == int8)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT8_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT8_MIN - this->getVal()))
				throw OverFlow_error("Int8 Overflow\n");
			return(new Int8Operand(type, sstr.str()));
		}
		else if (type == int16)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT16_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT16_MIN - this->getVal()))
				throw OverFlow_error("Int16 Overflow\n");
			return(new Int16Operand(type, sstr.str()));
		}
		else
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT32_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT32_MIN - this->getVal()))
				throw OverFlow_error("Int32 Overflow\n");
			return(new Int32Operand(type, sstr.str()));
		}
	}
	return(NULL);
}

IOperand const * Int8Operand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			val = static_cast<double>(this->_val.in8) * ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			val = static_cast<double>(this->_val.in8) * ptr->getVal();
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
		int val = this->_val.in8 * ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= INT8_MAX && val >= INT8_MIN)
		{
			type = int8;
			return(new Int8Operand(type, str));
		}
		else if (val <= INT16_MAX && val >= INT16_MIN )
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

IOperand const * Int8Operand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->_val.in8) / ptr->getVal();
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->_val.in8) * ptr->getVal();
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
		int val = this->_val.in8 / ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= INT8_MAX && val >= INT8_MIN)
		{
			type = int8;
			return(new Int8Operand(type, str));
		}
		else if (val <= INT16_MAX && val >= INT16_MIN )
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

IOperand const * Int8Operand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->_val.in8), ptr->getVal());
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if (ptr->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->_val.in8), ptr->getVal());
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
		int val = this->_val.in8 % ptr->getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= INT8_MAX && val >= INT8_MIN)
		{
			type = int8;
			return(new Int8Operand(type, str));
		}
		else if (val <= INT16_MAX && val >= INT16_MIN )
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

std::string const & Int8Operand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.in32; // should change to in8 as to just display the ascii charachters
	std::string *sstr = new std::string(str.str());
	return(*sstr);
}

Int8Operand::~Int8Operand( void )
{
	return;
}

int8_t	Int8Operand::getVal( void ) const
{
	return(this->_val.in8);
}