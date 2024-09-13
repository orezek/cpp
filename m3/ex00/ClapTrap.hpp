/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:02:16 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 10:50:31 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
	public:
		// Orthodox canonical form
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &other);
		// Member methods
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		// Member Getters
		int	getHitPoints(void);
		int getEnergyPoints(void);
		int getAttackDamage(void);
		std::string getName(void);
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};
