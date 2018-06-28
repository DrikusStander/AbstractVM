
#include "IOperand.hpp"
#include "Int32Operand.hpp"


Int32Operand::Int32Operand( void )
{
	return;
}

Int32Operand::Int32Operand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	long int temp = std::strtol(val.c_str(), NULL, 10);
	if (temp > INT32_MAX || temp < INT32_MIN)
		throw OverFlow_error("Int32 Overflow\n");
	this->_val.in32 = temp;
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
		int val ;
		if ((this->getVal() > 0 && ptr->getVal() > INT32_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT32_MIN - this->getVal()))
			throw OverFlow_error("Int32 Overflow\n");
		val = this->getVal() + ptr->getVal();
		sstr << val;
		return(new Int32Operand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator-( IOperand const & rhs ) const
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
		int val;
		if ((this->getVal() < 0 && ptr->getVal() > INT32_MAX + this->getVal()) || (this->getVal() > 0 && ptr->getVal() < INT32_MIN + this->getVal()))
			throw OverFlow_error("Int32 Overflow\n");
		val = this->getVal() - ptr->getVal();
		sstr << val;
		return(new Int32Operand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator*( IOperand const & rhs ) const
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
		int val;
		if ( CHECK1(this->getVal(), ptr->getVal(), INT32_MAX) || CHECK2(this->getVal(), ptr->getVal(), INT32_MIN) || 
			CHECK3(this->getVal(), ptr->getVal(), INT32_MAX) || CHECK4(this->getVal(), ptr->getVal(), INT32_MIN) )
			throw OverFlow_error("Int32 Overflow\n");
		val = this->getVal() * ptr->getVal();
		sstr << val;
		return(new Int32Operand(type, sstr.str()));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator/( IOperand const & rhs ) const
{
	std::stringstream sstr;
	eOperandType type;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
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
		if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
		if ((ptr->getVal() == INT32_MIN && this->getVal() == -1) || (this->getVal() == INT32_MIN && ptr->getVal() == -1))
			throw OverFlow_error("INT32 overflow\n");
		int val = this->getVal() / ptr->getVal();
		sstr << val;
		std::string str = sstr.str();
		return(new Int32Operand(type, str));
	}
	return(NULL);
}

IOperand const * Int32Operand::operator%( IOperand const & rhs ) const
{

	
	std::stringstream sstr;
	eOperandType type;
	type = (this->getType() < rhs.getType()) ? rhs.getType() : this->getType();
	if (dynamic_cast<const floatOperand*>(&rhs) || dynamic_cast<const doubleOperand*>(&rhs))
	{
		double val;
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
		if (ptr->getVal() == 0 || this->getVal() == 0)
			throw DivByZero_error("Can not divide by Zero\n");
		if ((ptr->getVal() == INT32_MIN && this->getVal() == -1) || (this->getVal() == INT32_MIN && ptr->getVal() == -1))
			throw OverFlow_error("INT32 overflow\n");
		int val = this->getVal() % ptr->getVal();
		sstr << val;
		std::string str = sstr.str();
		return(new Int32Operand(type, str));
	}
	return(NULL);
}

std::string const & Int32Operand::toString( void ) const
{
	std::stringstream str;
	str << this->getVal();
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
