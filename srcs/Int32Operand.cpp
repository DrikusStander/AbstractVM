
#include "IOperand.hpp"
#include "Int32Operand.hpp"

Int32Operand::Int32Operand( void )
{
	return;
}

Int32Operand::Int32Operand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	this->_val.in32 = std::atoi(val.c_str());
	std::cout << std::atoi(val.c_str()) << std::endl;	
	std::cout << this->_type << " " << this->_val.in32 << std::endl;
	return;
}

Int32Operand::Int32Operand(Int32Operand const & src)
{
	this->_val.in32 = src._val.in32;
	this->_type = src._type;
	return;
}

Int32Operand const & Int32Operand::operator=(Int32Operand const & rhs)
{
	this->_val = rhs._val;
	this->_type = rhs._type;
	return(*this);
}

int Int32Operand::getPrecision( void ) const
{
	return(this->_type);
}

eOperandType Int32Operand::getType( void ) const
{
	return(this->_type);
}

IOperand const * Int32Operand::operator+( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int32Operand*>(&rhs))
	{
		Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	store val;
	val.dl = this->_val.dl + ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.in32;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int32Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator-( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int32Operand*>(&rhs))
	{
		Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	store val;
	val.dl = this->_val.dl - ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.in32;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int32Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator*( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int32Operand*>(&rhs))
	{
		Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	store val;
	val.dl = this->_val.dl * ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.in32;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int32Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator/( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int32Operand*>(&rhs))
	{
		Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	store val;
	val.dl = this->_val.dl / ptr->_val.dl;
	std::stringstream sstr;
	sstr << val.dl;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int32Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator%( IOperand const & rhs ) const
{
	if (dynamic_cast<const Int32Operand*>(&rhs))
	{
		Int32Operand const *ptr = dynamic_cast<const Int32Operand*>(&rhs);
	
	store val;
	if (this->getPrecision() > 2 || ptr->getPrecision() > 2)
	{
		val.dl = fmod(this->_val.dl, ptr->_val.dl);
	}
	else
	{
		val.in32 = this->_val.in32 % ptr->_val.in32;
	}
	std::stringstream sstr;
	sstr << val.in32;
	eOperandType type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
	std::string str = sstr.str();
	return(new Int32Operand(type, str));
	}
	return(NULL);
}

std::string const & Int32Operand::toString( void ) const
{
	std::stringstream str;
	str << this->_val.in32;
	std::string *sstr = new std::string(str.str());
	return(*sstr);
}

Int32Operand::~Int32Operand( void )
{
	return;
}

int32_t	Int32Operand::getVal( void ) const
{
	return(this->_val.in32);
}