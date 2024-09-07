/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:32:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 15:40:07 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name);
	void attack(void);
	void setWeapon(Weapon &type);

	private:
	std::string name;
	Weapon *weapon;
	HumanB();
};
