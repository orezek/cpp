/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:41:04 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 14:36:03 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << getType() << " default constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->_brain = new Brain(*obj._brain);
	this->_type = obj._type;
	std::cout << getType() << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << getType() << " destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		delete this->_brain;
		this->_brain = new Brain(*obj._brain);
		Animal::operator=(obj);
		this->_type = obj._type;
	}
	std::cout << getType() << " assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << " makes woof woof" << std::endl;
}

// Testing functions

void Dog::displayBrainAddress() const
{
	std::cout << "Memory address of Dog's Brain: " << _brain << std::endl;
}

void Dog::printIdeas(int count) const
{
	_brain->printIdeas(count);
}

void Dog::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}
