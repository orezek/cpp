/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:14:42 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 12:06:18 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
{
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has ben set for mission by the default constructor." << std::endl;
};
// Parametrized constructor
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << name << " has ben set for mission by string constructor." << std::endl;
};
// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap a new copy of " << this->_name <<" was created by copy constructor" << std::endl;
}
// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "<<this->_name << " was destroyed by destructor" << std::endl;
};
// Asignment operator
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

/*
When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
*/
// can ClapTrap has 0 energy points and have _hitPoints > 0? Yes, so what is make ClapTrap alive?
// Energy points or hit points?
void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacs " << target << " causing "<< this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << " because of low energy or hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot take more damages as he/she/it is dead.";
		std::cout << " Number of hit points: " << this->_hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes damage causing " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repeired by " << amount << " points!" << std::endl;

	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot be repaired due to low of energy points " << this->_energyPoints << std::endl;
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


/*
Clarification of Each Concept:
Hit Points (_hitPoints):

What it does: Tracks how much health or life the ClapTrap has.
Impact of attack: Decreases when ClapTrap takes damage.
Cannot perform actions if hitPoints == 0.
Attack Damage (_attackDamage):

What it does: Defines how much damage the ClapTrap inflicts on another object when it attacks.
Impact of attack: Reduces the target's hit points by this amount when attacking.
Does not affect ClapTrap's own health.
Energy Points (_energyPoints):

What it does: Tracks the energy ClapTrap needs to perform actions (attack/repair).
Impact of attack/repair: Each action costs 1 energy point.
Cannot perform actions if energyPoints == 0.

*/
