
#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>

typedef struct	s_stack	t_stack;

struct	s_stack
{
	void	*val;
	t_stack *next;
};

class Stack
{
	private:
		t_stack *_top_of_stack;
	protected:
	public:
		Stack( void );
		Stack( Stack const & src);
		~Stack( void );
		Stack & operator=(Stack const & rhs);
		t_stack * getTopOfStack( void );
		void	addToStack(t_stack &item);
		void	removeFromStack();
};

#endif
