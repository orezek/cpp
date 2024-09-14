/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:45:59 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 10:44:38 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << this->getType() << " default constructor called" << std::endl;
};

Animal::Animal (const Animal &obj)
{
	this->_type = obj._type;
	std::cout << this->getType() << " copy constructor called" << std::endl;
};

Animal::~Animal()
{
	std::cout << this->getType() << " destructor called" << std::endl;
};

Animal &Animal::operator=(const Animal &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << this->getType() << " copy assignment operator called" << std::endl;
	return (*this);
};

void Animal::makeSound(void) const
{
	std::cout << this->getType() << "s make sound" << std::endl;
}

std::string Animal:: getType(void) const
{
	return (this->_type);
}
