
#include "IOperand.hpp"
#include "doubleOperand.hpp"

doubleOperand::doubleOperand( void )
{
	return;
}

doubleOperand::doubleOperand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	this->_val.dl = std::atof(val.c_str());
	std::cout << std::atof(val.c_str()) << std::endl;	
	std::cout << this->_type << " " << this->_val.dl << std::endl;
	return;
}

doubleOperand::doubleOperand(doubleOperand const & src)
{
	this->_val.dl = src._val.dl;
	this->_type = src._type;
	return;
}

doubleOperand const & doubleOperand::operator=(doubleOperand const & rhs)
{
	this->_val = rhs._val;
	this->_type = rhs._type;
	return(*this);
}

int doubleOperand::getPrecision( void ) const
{
	return(this->_type);
}

eOperandType doubleOperand::getType( void ) const
{
	return(this->_type);
}

IOperand const * doubleOperand::operator+( IOperand const & rhs ) const
{
	if (dynamic_cast<const doubleOperand*>(&rhs))
	{
		doubleOperand const *ptr = dynamic_cast<const doubleOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl + ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new doubleOperand(type, str));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator-( IOperand const & rhs ) const
{
	if (dynamic_cast<const doubleOperand*>(&rhs))
	{
		doubleOperand const *ptr = dynamic_cast<const doubleOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl - ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new doubleOperand(type, str));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const doubleOperand*>(&rhs))
	{
		doubleOperand const *ptr = dynamic_cast<const doubleOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl * ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new doubleOperand(type, str));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const doubleOperand*>(&rhs))
	{
		doubleOperand const *ptr = dynamic_cast<const doubleOperand*>(&rhs);
	store val;
	val.dl = this->_val.dl / ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new doubleOperand(type, str));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const doubleOperand*>(&rhs))
	{
		doubleOperand const *ptr = dynamic_cast<const doubleOperand*>(&rhs);
	
	store val;
	if (this->getPrecision() > 2 || ptr->getPrecision() > 2)
	{
		val.dl = fmod(this->_val.dl, ptr->_val.dl);
	}
	// else
	// {
	// 	val.dl = this->_val.dl % ptr->_val.dl;
	// }
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new doubleOperand(type, str));
	}
	return(NULL);
}

std::string const & doubleOperand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.dl;
	std::string *sstr = new std::string(str.str());
	return(*sstr);
}

doubleOperand::~doubleOperand( void )
{
	return;
}

double	doubleOperand::getVal( void ) const
{
	return(this->_val.dl);
}