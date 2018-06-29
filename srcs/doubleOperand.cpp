
#include "IOperand.hpp"
#include "doubleOperand.hpp"

doubleOperand::doubleOperand( void )
{
	return;
}

doubleOperand::doubleOperand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	double temp = std::strtod(val.c_str(), NULL);
	if (temp > DBL_MAX || temp < -DBL_MAX || errno == ERANGE)
		throw OverFlow_error("Double Overflow\n");
	this->_val.dl = temp;
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
	eOperandType type;
	std::stringstream sstr;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	double val;
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		if (dynamic_cast<const floatOperand*>(&rhs))
		{
			floatOperand const *ptr = reinterpret_cast<const floatOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	else
	{
		if (dynamic_cast<const Int8Operand*>(&rhs))
		{
			Int8Operand const *ptr = reinterpret_cast<const Int8Operand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
		}
		else if (dynamic_cast<const Int16Operand*>(&rhs))
		{
			Int16Operand const *ptr = reinterpret_cast<const Int16Operand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
		}
		else
		{
			Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
			if ((this->getVal() > 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < -DBL_MAX - this->getVal()))
				throw OverFlow_error("Float Overflow\n");
			val = static_cast<double>(this->getVal()) + ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator-( IOperand const & rhs ) const
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
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	else
	{
		if (dynamic_cast<const Int8Operand*>(&rhs))
		{
			Int8Operand const *ptr = reinterpret_cast<const Int8Operand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
		}
		else if (dynamic_cast<const Int16Operand*>(&rhs))
		{
			Int16Operand const *ptr = reinterpret_cast<const Int16Operand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
		}
		else
		{
			Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
			if ((this->getVal() < 0 && ptr->getVal() > DBL_MAX - this->getVal()) || (this->getVal() > 0 && ptr->getVal() < -DBL_MAX + this->getVal()))
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) - ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator*( IOperand const & rhs ) const
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
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
		}
		else
		{
			doubleOperand const *ptr = reinterpret_cast<const doubleOperand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	else
	{
		if (dynamic_cast<const Int8Operand*>(&rhs))
		{
			Int8Operand const *ptr = reinterpret_cast<const Int8Operand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
		}
		else if (dynamic_cast<const Int16Operand*>(&rhs))
		{
			Int16Operand const *ptr = reinterpret_cast<const Int16Operand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
		}
		else
		{
			Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
			if ( CHECK1(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK2(this->getVal(), ptr->getVal(), -DBL_MAX) || 
				CHECK3(this->getVal(), ptr->getVal(), DBL_MAX) || CHECK4(this->getVal(), ptr->getVal(), -DBL_MAX) )
				throw OverFlow_error("Double Overflow\n");
			val = static_cast<double>(this->getVal()) * ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator/( IOperand const & rhs ) const
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
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
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
		}
		return(new doubleOperand(type, sstr.str()));
	}
	else
	{
		if (dynamic_cast<const Int8Operand*>(&rhs))
		{
			Int8Operand const *ptr = reinterpret_cast<const Int8Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
		}
		else if (dynamic_cast<const Int16Operand*>(&rhs))
		{
			Int16Operand const *ptr = reinterpret_cast<const Int16Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
		}
		else
		{
			Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = static_cast<double>(this->getVal()) / ptr->getVal();
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * doubleOperand::operator%( IOperand const & rhs ) const
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
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
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
		}
		return(new doubleOperand(type, sstr.str()));
	}
	else
	{
		if (dynamic_cast<const Int8Operand*>(&rhs))
		{
			Int8Operand const *ptr = reinterpret_cast<const Int8Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
		}
		else if (dynamic_cast<const Int16Operand*>(&rhs))
		{
			Int16Operand const *ptr = reinterpret_cast<const Int16Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
		}
		else
		{
			Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
			if ( (this->getVal() == -DBL_MAX && ptr->getVal() == -1) || (ptr->getVal() == -DBL_MAX && this->getVal() == -1) )
				throw OverFlow_error("Double overflow\n");
			if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
			val = fmod(static_cast<double>(this->getVal()), ptr->getVal());
			sstr << val;
		}
		return(new doubleOperand(type, sstr.str()));
	}
	return(NULL);
}

std::string const & doubleOperand::toString( void ) const
{
	std::stringstream str;
	str << this->getVal();
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
