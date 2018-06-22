
#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>
#include "IOperand.hpp"
#include "Exceptions.hpp"

struct	t_stack
{
	IOperand const	*val;
	t_stack			*next;
};

class Stack
{
	private:
		t_stack		*_top_of_stack;
		int			_size_of_stack;
	protected:
	public:
		Stack( void );
		Stack( Stack const & src);
		~Stack( void );
		Stack & operator=(Stack const & rhs);
		t_stack * getTopOfStack( void );
		void	addToStack(t_stack *item);
		void	removeFromStack( void );
		void	dumpStack( void );
		int		getStackSize( void );
};

#endif
