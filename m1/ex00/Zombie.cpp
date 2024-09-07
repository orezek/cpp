/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:21:37 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 08:47:39 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name)
{
	this->name = name;
}
// destructor
Zombie::~Zombie(void)
{
	std::cout << "Zombie destroyed: ";
	std::cout << this->name << std::endl;
}

// instance method
void Zombie::announce (void)
{
	std::cout << this->name << " :" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

