/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:13:02 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 11:15:16 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << getType() << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	this->_type = obj._type;
	std::cout << getType() << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << getType() << " destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
	{
		WrongAnimal::operator=(obj);
		this->_type = obj._type;
	}
	std::cout << getType() << " assignment operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " makes meow" << std::endl;
}
