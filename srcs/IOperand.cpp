
#include "IOperand.hpp"

Int8Operand::Int8Operand( void )
{
	return;
}

Int8Operand::Int8Operand( eOperandType & type, std::string const &val)
{
	this->_type = type;
	long int temp = std::strtol(val.c_str(), NULL, 10);
	if (temp > INT8_MAX || temp < INT8_MIN)
		throw OverFlow_error("Int8 Overflow\n");
	this->_val.in8 = temp;
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
		int val ;
		
		if (type == int8)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT8_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT8_MIN - this->getVal()))
				throw OverFlow_error("Int8 Overflow\n");
			val = this->getVal() + ptr->getVal();
			sstr << val;
			return(new Int8Operand(type, sstr.str()));
		}
		else if (type == int16)
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT16_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT16_MIN - this->getVal()))
				throw OverFlow_error("Int16 Overflow\n");
			val = this->getVal() + ptr->getVal();
			sstr << val;
			return(new Int16Operand(type, sstr.str()));
		}
		else
		{
			if ((this->getVal() > 0 && ptr->getVal() > INT32_MAX - this->getVal()) || (this->getVal() < 0 && ptr->getVal() < INT32_MIN - this->getVal()))
				throw OverFlow_error("Int32 Overflow\n");
			val = this->getVal() + ptr->getVal();
			sstr << val;
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
		if (type == int8)
		{
			if ((this->getVal() < 0 && ptr->getVal() > INT8_MAX + this->getVal()) || (this->getVal() > 0 && ptr->getVal() < INT8_MIN + this->getVal()))
				throw OverFlow_error("Int8 Overflow\n");
			val = this->getVal() - ptr->getVal();
			sstr << val;
			return(new Int8Operand(type, sstr.str()));
		}
		else if (type == int16)
		{
			if ((this->getVal() < 0 && ptr->getVal() > INT16_MAX + this->getVal()) || (this->getVal() > 0 && ptr->getVal() < INT16_MIN + this->getVal()))
				throw OverFlow_error("Int16 Overflow\n");
			val = this->getVal() - ptr->getVal();
			sstr << val;
			return(new Int16Operand(type, sstr.str()));
		}
		else
		{
			if ((this->getVal() < 0 && ptr->getVal() > INT32_MAX + this->getVal()) || (this->getVal() > 0 && ptr->getVal() < INT32_MIN + this->getVal()))
				throw OverFlow_error("Int32 Overflow\n");
			val = this->getVal() - ptr->getVal();
			sstr << val;
			return(new Int32Operand(type, sstr.str()));
		}
	}
	return(NULL);
}

IOperand const * Int8Operand::operator*( IOperand const & rhs ) const
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
		if (type == int8)
		{
			if ( CHECK1(this->getVal(), ptr->getVal(), INT8_MAX) || CHECK2(this->getVal(), ptr->getVal(), INT8_MIN) || 
				CHECK3(this->getVal(), ptr->getVal(), INT8_MAX) || CHECK4(this->getVal(), ptr->getVal(), INT8_MIN) )
				throw OverFlow_error("Int8 Overflow\n");
			val = this->getVal() * ptr->getVal();
			sstr << val;
			return(new Int8Operand(type, sstr.str()));
		}
		else if (type == int16)
		{
			if ( CHECK1(this->getVal(), ptr->getVal(), INT16_MAX) || CHECK2(this->getVal(), ptr->getVal(), INT16_MIN) || 
				CHECK3(this->getVal(), ptr->getVal(), INT16_MAX) || CHECK4(this->getVal(), ptr->getVal(), INT16_MIN) )
				throw OverFlow_error("Int16 Overflow\n");
			val = this->getVal() * ptr->getVal();
			sstr << val;
			return(new Int16Operand(type, sstr.str()));
		}
		else
		{
			if ( CHECK1(this->getVal(), ptr->getVal(), INT32_MAX) || CHECK2(this->getVal(), ptr->getVal(), INT32_MIN) || 
				CHECK3(this->getVal(), ptr->getVal(), INT32_MAX) || CHECK4(this->getVal(), ptr->getVal(), INT32_MIN) )
				throw OverFlow_error("Int32 Overflow\n");
			val = this->getVal() * ptr->getVal();
			sstr << val;
			return(new Int32Operand(type, sstr.str()));
		}
	}
	return(NULL);
}

IOperand const * Int8Operand::operator/( IOperand const & rhs ) const
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
			val = static_cast<double>(this->_val.in8) / ptr->getVal();
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
			val = static_cast<double>(this->_val.in8) / ptr->getVal();
			sstr << val;
			return(new doubleOperand(type, sstr.str()));
		}
	}
	else
	{
		Int32Operand const *ptr = reinterpret_cast<const Int32Operand*>(&rhs);
		if (ptr->getVal() == 0 || this->getVal() == 0)
				throw DivByZero_error("Can not divide by Zero\n");
		if (type == int8)
		{
			if ( (this->getVal() == INT8_MIN && ptr->getVal() == -1) || (ptr->getVal() == INT8_MIN && this->getVal() == -1) )
				throw OverFlow_error("INT8 overflow\n");
			int val = this->getVal() / ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int8Operand(type, str));
		}
		else if (type == int16)
		{
			if (ptr->getVal() == INT16_MIN && this->getVal() == -1)
				throw OverFlow_error("INT16 overflow\n");
			int val = this->getVal() / ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int16Operand(type, str));
		}
		else
		{
			if (ptr->getVal() == INT32_MIN && this->getVal() == -1)
				throw OverFlow_error("INT32 overflow\n");
			int val = this->getVal() / ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int32Operand(type, str));

		}
	}
	return(NULL);
}

IOperand const * Int8Operand::operator%( IOperand const & rhs ) const
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
		if (type == int8)
		{
			if ( (this->getVal() == INT8_MIN && ptr->getVal() == -1) || (ptr->getVal() == INT8_MIN && this->getVal() == -1) )
				throw OverFlow_error("INT8 overflow\n");
			int val = this->getVal() % ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int8Operand(type, str));
		}
		else if (type == int16)
		{
			if (ptr->getVal() == INT16_MIN && this->getVal() == -1)
				throw OverFlow_error("INT16 overflow\n");
			int val = this->getVal() % ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int16Operand(type, str));
		}
		else
		{
			if (ptr->getVal() == INT32_MIN && this->getVal() == -1)
				throw OverFlow_error("INT32 overflow\n");
			int val = this->getVal() % ptr->getVal();
			sstr << val;
			std::string str = sstr.str();
			return(new Int32Operand(type, str));
		}
	}
	return(NULL);
}

std::string const & Int8Operand::toString( void ) const
{
	std::stringstream str;
	str << static_cast<int32_t>(this->_val.in8);
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