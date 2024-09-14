/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:43:36 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 10:39:10 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << getType() << " default constructor called" << std::endl;
};

Cat::Cat(const Cat &obj) : Animal()
{
	this->_type = obj._type;
	std::cout << getType() << " copy constructor called" << std::endl;
};

Cat::~Cat()
{
	std::cout << getType() << " destructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	std::cout << getType() << " assignment operator called" << std::endl;
	return (*this);
};

void Cat::makeSound(void) const
{
	std::cout << this->getType() << " makes mew ooh" << std::endl;
}
