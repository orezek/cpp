/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:09:54 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:19:49 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
# include <iostream>

Weapon::Weapon(std::string type) : type(type){};
Weapon::~Weapon() {};

const std::string Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}
