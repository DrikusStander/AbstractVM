
#include "Stack.hpp"

Stack::Stack( void )
{
	this->_top_of_stack = NULL;	
	return;
}

Stack::Stack( Stack const & src)
{
	this->_top_of_stack = src._top_of_stack;
}

Stack::~Stack( void )
{
	return;
}

Stack & Stack::operator=(Stack const & rhs)
{
	this->_top_of_stack = rhs._top_of_stack;
	return (*this);
}

t_stack * Stack::getTopOfStack( void )
{
	return(this->_top_of_stack);
}

void	Stack::addToStack(t_stack *item)
{
	if (this->_top_of_stack)
	{
		item->next = this->_top_of_stack;
	}
	this->_top_of_stack = item;
}

void	Stack::removeFromStack( void )
{
	t_stack *temp;
	temp = this->_top_of_stack->next;
	delete this->_top_of_stack;
	this->_top_of_stack = temp;
	temp = NULL;
}

void	Stack::printStack( void )
{
	t_stack *lst;
	lst = this->_top_of_stack;
	while (lst)
	{
		std::cout << lst->val.in32;
		if (lst->next)
			std::cout << " ";
		lst = lst->next;
	}
	std::cout << std::endl;
}