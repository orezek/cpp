/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:16:59 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 12:40:41 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

/*
Public, Protected, and Private Inheritance:

Public inheritance: (public BaseClass) means that public and
protected members of the base class will retain their access
levels in the derived class.

Protected inheritance: (protected BaseClass) means that public and
protected members of the base class will become protected in the derived class.

Private inheritance: (private BaseClass) means that all members of
the base class will become private in the derived class.
*/

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate(void);
	private:
		// empty -all inherited from ClapTrap
};
