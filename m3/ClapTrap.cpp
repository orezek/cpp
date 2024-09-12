/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:14:42 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 22:05:48 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){};
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << name << " has ben set for mission by string constructor." << std::endl;
};
// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap a new copy of " << this->_name <<" was created by copy constructor" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "<<this->_name << " was destroyed by destructor" << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	std::cout << "ClapTrap assignment operator was used to set a new warrior ";
	std::cout << this->_name << std::endl;
	return (*this);
}


void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap" << this->_name << " attacs " << target << " causing "<< this->_attackDamage << "points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap" << this->_name << " cannot attack " << target << "because of low energy or hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes damage causing " << this->_hitPoints << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " has repeired itself!" << std::endl;
}

int	ClapTrap::getHitPoints(void)
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void)
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

std::string ClapTrap::getName(void)
{
	return (this->_name);
}
