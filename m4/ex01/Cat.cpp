/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:43:36 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 14:37:47 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << getType() << " default constructor called" << std::endl;
};

Cat::Cat(const Cat &obj) : Animal()
{
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
	std::cout << getType() << " copy constructor called" << std::endl;
};

Cat::~Cat()
{
	delete this->_brain;
	std::cout << getType() << " destructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		this->_type = obj._type;
		delete this->_brain; // delete old brain
		this->_brain = new Brain(*obj._brain); // assign deep copy
	}
	std::cout << getType() << " assignment operator called" << std::endl;
	return (*this);
};

void Cat::makeSound(void) const
{
	std::cout << this->getType() << " makes mew ooh" << std::endl;
}

// Testing functions
void Cat::displayBrainAddress() const
{
	std::cout << "Memory address of Cat's Brain: " << _brain << std::endl;
}

void Cat::printIdeas(int count) const
{
	_brain->printIdeas(count);
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}



// The whole example could be done by STATIC allocation not DYNAMIC
// Pros
	// no memory management all memory is allocated in the stack
// Cons
	// the brain object is fixed to the cat object - cannot be changed
	// the brian object is created when cat object is created

// Dynamic allocation
// Pros
	// the brain object can be created anytime and can be changed to any other brain object
// Cons
	// memory management needed to prevent leaks
