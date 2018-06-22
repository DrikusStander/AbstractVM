
#include "IOperand.hpp"

Int8Operand::Int8Operand( void )
{
	return;
}

Int8Operand::Int8Operand( eOperandType & type, std::string const &val)
{
	std::cout << "Int8Operand constructor val str: " << val << std::endl;	
	this->_type = type;
	this->_val.in8 = std::atoi(val.c_str());
	std::cout << "Int8Operand constructor atoi: " << std::atoi(val.c_str()) << std::endl;	
	std::cout << "Int8Operand constructor type: "<< this->_type << " value : " << this->_val.in8 << std::endl;
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
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		std::cout << "Int8Operand + fl/dbl :" << std::endl;
		// Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
		double val = this->_val.in8 + rhs.getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= FLT_MAX && val => -FLT_MAX)
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
	else //(dynamic_cast<const Int8Operand*>(&rhs))
	{
		std::cout << "Int8Operand + Int8Operand :" << std::endl;
		// Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
		int val = this->_val.in8 + rhs.getVal();
		std::stringstream sstr;
		sstr << val;
		std::string str = sstr.str();
		eOperandType type;
		if (val <= INT8_MAX && val => INT8_MIN)
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
			type = int13;
			return(new Int32Operand(type, str));
		}
	}
	// else if (dynamic_cast<const Int32Operand*>(&rhs))
	// {
	// 	std::cout << "Int8Operand + Int32Operand :" << std::endl;
	// 	Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	// 	store val;
	// 	val.in32 = this->_val.in8 + ptr->getVal();
	// 	std::stringstream sstr;
	// 	sstr << val.in32;
	// 	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	// 	std::string str = sstr.str();
	// 	return(new Int32Operand(type, str));
	// }
	return(NULL);
}

IOperand const * Int8Operand::operator-( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int8Operand*>(&rhs))
	{
		Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
	store val;
	val.in8 = this->_val.in8 - ptr->_val.in8;
	std::stringstream sstr;
	sstr << val.in8;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int8Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int8Operand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int8Operand*>(&rhs))
	{
		Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
	store val;
	val.in8 = this->_val.in8 * ptr->_val.in8;
	std::stringstream sstr;
	sstr << val.in8;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int8Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int8Operand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int8Operand*>(&rhs))
	{
		Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
	store val;
	val.in8 = this->_val.in8 / ptr->_val.in8;
	std::stringstream sstr;
	sstr << val.in8;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int8Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int8Operand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int8Operand*>(&rhs))
	{
		Int8Operand const *ptr = dynamic_cast<const Int8Operand*>(&rhs);
	
	store val;
	if (this->getPrecision() > 2 || ptr->getPrecision() > 2)
	{
		val.dl = fmod(this->_val.dl, ptr->_val.dl);
	}
	else
	{
		val.in8 = this->_val.in8 % ptr->_val.in8;
	}
	std::stringstream sstr;
	sstr << val.in8;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int8Operand(type, str));
	}
	return(NULL);
}

std::string const & Int8Operand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.in32;
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