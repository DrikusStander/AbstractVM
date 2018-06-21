
#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>

struct	t_stack
{
	union store
	{
		std::int8_t in8;
		std::int16_t in16;
		std::int32_t in32;
		float fl;
		double dl;
	};

	enum type
	{
		INT8 = 0,
		INT16,
		INT32,
		FLT,
		DBL
	};

	store	val;
	type	val_type;
	t_stack	*next;
};

class Stack
{
	private:
		struct t_stack *_top_of_stack;
	protected:
	public:
		Stack( void );
		Stack( Stack const & src);
		~Stack( void );
		Stack & operator=(Stack const & rhs);
		t_stack * getTopOfStack( void );
		void	addToStack(t_stack *item);
		void	removeFromStack( void );
		void	printStack( void );
};

#endif
