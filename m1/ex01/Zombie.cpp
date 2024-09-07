/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:16:38 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 10:25:49 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name) : name(name) {};
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
// Setter method 
void	Zombie::setName(std:: string name)
{
	this->name = name;
}
