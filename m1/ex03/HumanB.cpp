/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:45:19 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:49:13 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB(std::string name) : name(name) {};

HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon << std::endl;
}

void HumanB::setWeapon(Weapon type)
{
	this.weapon = type;
}
