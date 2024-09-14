/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:41:04 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 10:50:55 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << getType() << " default constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->_type = obj._type;
	std::cout << getType() << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << getType() << " destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
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

