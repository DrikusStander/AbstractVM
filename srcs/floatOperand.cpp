
#include "IOperand.hpp"
#include "floatOperand.hpp"

floatOperand::floatOperand( void )
{
	return;
}

floatOperand::floatOperand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	double temp = std::strtod(val.c_str(), NULL);
	if (temp > FLT_MAX || temp < FLT_MIN || errno == ERANGE)
		throw OverFlow_error("Int16 Overflow\n");
	this->_val.fl = temp;
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
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
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
		if ((this->getVal() > 0 && ptr->getVal() > FLT_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -FLT_MAX - this->getVal()))
			throw OverFlow_error("Float Overflow\n");
		val = static_cast<double>(this->getVal()) + ptr->getVal();
		sstr << val;
		return(new floatOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * floatOperand::operator-( IOperand const & rhs ) const
{
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > FLT_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -FLT_MAX + this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
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
		if ((this->getVal() < 0 && ptr->getVal() > FLT_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -FLT_MAX + this->getVal()))
			throw OverFlow_error("Float Overflow\n");
		val = static_cast<double>(this->getVal()) - ptr->getVal();
		sstr << val;
		return(new floatOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * floatOperand::operator*( IOperand const & rhs ) const
{
	std::cout << "float MUL" << std::endl;
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), FLT_MAX) || CHECK2(this->getVal(), ptr->getVal(), -FLT_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), FLT_MAX) || CHECK4(this->getVal(), ptr->getVal(), -FLT_MAX) )
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			std::cout << "DBL_MAX : " << DBL_MAX << std::endl;
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		val = static_cast<double>(this->getVal()) * ptr->getVal();
		std::cout << "float mul val: " << val << std::endl;
		if ( CHECK1(this->getVal(), ptr->getVal(), FLT_MAX) || CHECK2(this->getVal(), ptr->getVal(), -FLT_MAX) || 
			CHECK3(this->getVal(), ptr->getVal(), FLT_MAX) || CHECK4(this->getVal(), ptr->getVal(), -FLT_MAX) )
			throw OverFlow_error("Float Overflow\n");
		val = static_cast<double>(this->getVal()) * ptr->getVal();
		sstr << val;
		return(new floatOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * floatOperand::operator/( IOperand const & rhs ) const
{
	std::stringstream sstr;
	eOperandType type;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ( (this->getVal() == -FLT_MAX && ptr->getVal() == -1) || (ptr->getVal() == -FLT_MAX && this->getVal() == -1) )
				throw OverFlow_error("Float overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		if ( (this->getVal() == -FLT_MAX && ptr->getVal() == -1) || (ptr->getVal() == -FLT_MAX && this->getVal() == -1) )
			throw OverFlow_error("Float overflow\n");
		if (ptr->getVal() == 0 || this->getVal() == 0)
			throw DivByZero_error("Can not divide by Zero\n");
		val = static_cast<double>(this->getVal()) / ptr->getVal();
		sstr << val;
		return(new floatOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * floatOperand::operator%( IOperand const & rhs ) const
{

	
	std::stringstream sstr;
	eOperandType type;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ( (this->getVal() == -FLT_MAX && ptr->getVal() == -1) || (ptr->getVal() == -FLT_MAX && this->getVal() == -1) )
				throw OverFlow_error("Float overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
			return(new floatOperand(type, sstr.str()));
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		if ( (this->getVal() == -FLT_MAX && ptr->getVal() == -1) || (ptr->getVal() == -FLT_MAX && this->getVal() == -1) )
			throw OverFlow_error("Float overflow\n");
		if (ptr->getVal() == 0 || this->getVal() == 0)
			throw DivByZero_error("Can not divide by Zero\n");
		val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
		sstr << val;
		return(new floatOperand(type, sstr.str()));
	}
	return(NULL);
}

std::string const & floatOperand::toString( void ) const
{
	std::stringstream str;
	str << this->getVal();
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
