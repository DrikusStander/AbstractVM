
#include "Stack.hpp"

Stack::Stack( void )
{
	this->_top_of_stack = NULL;
	this->_size_of_stack = 0;
	return;
}

Stack::Stack( Stack const & src)
{
	this->_top_of_stack = src._top_of_stack;
	this->_size_of_stack = src._size_of_stack;
	
}

Stack::~Stack( void )
{
	return;
}

Stack & Stack::operator=(Stack const & rhs)
{
	this->_top_of_stack = rhs._top_of_stack;
	this->_size_of_stack = rhs._size_of_stack;	
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
	if (this->_top_of_stack)
		this->_size_of_stack++;
	std::cout << "added to stack" << std::endl;
}

void	Stack::removeFromStack( void )
{
	t_stack *temp;
	if (this->_top_of_stack)
	{
		temp = this->_top_of_stack->next;
		delete this->_top_of_stack->val;
		this->_top_of_stack->val = NULL;
		delete this->_top_of_stack;
		this->_top_of_stack = temp;
		this->_size_of_stack--;
	}
	else
	{
		throw Stack_error("No items to pop\n");
	}
	temp = NULL;
}

void	Stack::dumpStack( void )
{
	t_stack *lst;
	lst = this->_top_of_stack;
	std::cout << "**************** stack Dump *************" << std::endl;
	while (lst)
	{
		if (lst->val)
		{
			std::string	const *temp = &lst->val->toString();
			std::cout << *temp << std::endl;
			delete temp;
		}
		lst = lst->next;
	}
	std::cout << "**************** ********* *************" << std::endl;
}

int		Stack::getStackSize( void )
{
	return(this->_size_of_stack);
}