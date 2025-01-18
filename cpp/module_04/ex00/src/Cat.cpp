#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " says: ** Meow? **" << std::endl;
}
