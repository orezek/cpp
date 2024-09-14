/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:45:59 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 11:09:35 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << this->getType() << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->_type = obj._type;
	std::cout << this->getType() << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << this->getType() << " copy assignment operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << "s make sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
