/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:17:02 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 13:01:48 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "default";
	this->_hitPoints = 0; // 100
	this->_energyPoints = 0; // 50
	this->_attackDamage = 0; // 20
	std::cout << "ScavTrap " << this->_name << " has ben commissioned by default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has ben commissioned by parametrized constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	std::cout << "ScavTrap " << this->_name << " has ben commissioned by copy constructor!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_attackDamage = obj._attackDamage;
		this->_energyPoints = obj._energyPoints;
		this->_hitPoints = obj._hitPoints;
	}
	std::cout << "ScavTrap " << this->_name << " has ben commissioned by assignment operator!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "<<this->_name << " was destroyed by destructor" << std:: endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacs " << target << " causing "<< this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target << " because of low energy or hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode." << std::endl;
}
