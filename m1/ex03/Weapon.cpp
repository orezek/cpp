/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:09:54 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 15:15:53 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include <iostream>

Weapon::Weapon(std::string type) : type(type){};
Weapon::~Weapon()
{
	std::cout << "Weapon destroyed: ";
	std::cout << this->type << std::endl;
};

const std::string &Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}
