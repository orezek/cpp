/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:29:08 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 13:45:24 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
Is the Call to ClapTrap() Needed?
If you omit the ClapTrap() call, C++ will implicitly call the default
constructor of the base class anyway. So technically, in this specific case,
it is not strictly required to write : ClapTrap() in the initializer list,
since it will happen implicitly.

However, including it explicitly makes the code more readable and makes the
constructor behavior clear, especially when multiple constructors are involved.
*/


FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "default";
	this->_hitPoints = 0; // 100
	this->_energyPoints = 0; // 100
	this->_attackDamage = 0; // 30
	std::cout << "FragTrap " << this->_name << " has ben commissioned by default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "FragTrap " << this->_name << " has ben commissioned by parametrized constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	std::cout << "FragTrap " << this->_name << " has ben commissioned by copy constructor!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_attackDamage = obj._attackDamage;
		this->_energyPoints = obj._energyPoints;
		this->_hitPoints = obj._hitPoints;
	}
	std::cout << "FragTrap " << this->_name << " has ben commissioned by assignment operator!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<<this->_name << " was destroyed by destructor" << std:: endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": Positive high-five request!" << std::endl;
}
