/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:34:14 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:43:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA(std::string name, Weapon weapon) : name(name), weapon(weapon) {};

HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon << std::endl;
}
