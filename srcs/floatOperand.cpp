
#include "IOperand.hpp"
#include "floatOperand.hpp"

floatOperand::floatOperand( void )
{
	return;
}

floatOperand::floatOperand( eOperandType & type, std::string const &val)
{
	std::cout << "float constructor" << std::endl;
	this->_type = type;
	this->_val.fl = std::atof(val.c_str());
	std::cout << std::atof(val.c_str()) << std::endl;	
	std::cout << this->_type << " " << this->_val.fl << std::endl;
	return;
}

floatOperand::floatOperand(floatOperand const & src)
{
	this->_val.fl = src._val.fl;
	this->_type = src._type;
	return;
}

floatOperand const & floatOperand::operator=(floatOperand const & rhs)
{
	this->_val = rhs._val;
	this->_type = rhs._type;
	return(*this);
}

int floatOperand::getPrecision( void ) const
{
	return(this->_type);
}

eOperandType floatOperand::getType( void ) const
{
	return(this->_type);
}

IOperand const * floatOperand::operator+( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs))
	{
		floatOperand const *ptr = dynamic_cast<const floatOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl + ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.fl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new floatOperand(type, str));
	}
	return(NULL);
}

IOperand const * floatOperand::operator-( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs))
	{
		floatOperand const *ptr = dynamic_cast<const floatOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl - ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.fl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new floatOperand(type, str));
	}
	return(NULL);
}

IOperand const * floatOperand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs))
	{
		floatOperand const *ptr = dynamic_cast<const floatOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl * ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.fl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new floatOperand(type, str));
	}
	return(NULL);
}

IOperand const * floatOperand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs))
	{
		floatOperand const *ptr = dynamic_cast<const floatOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl / ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new floatOperand(type, str));
	}
	return(NULL);
}

IOperand const * floatOperand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const floatOperand*>(&rhs))
	{
		floatOperand const *ptr = dynamic_cast<const floatOperand*>(&rhs);
	
	store val;
	if (this->getPrecision() > 2 || ptr->getPrecision() > 2)
	{
		val.dl = fmod(this->_val.dl, ptr->_val.dl);
	}
	// else
	// {
	// 	val.fl = this->_val.fl % ptr->_val.fl;
	// }
	std::stringstream sstr;
	sstr << val.fl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new floatOperand(type, str));
	}
	return(NULL);
}

std::string const & floatOperand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.fl;
	std::string *sstr = new std::string(str.str());
	return(*sstr);
}

floatOperand::~floatOperand( void )
{
	return;
}

float	floatOperand::getVal( void ) const
{
	return(this->_val.fl);
}