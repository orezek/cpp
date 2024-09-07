/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:32:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:46:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class HumanB
{
	public:
	HumanB(std::string name);
	void attack(void);
	void setWeapon(Weapon type);

	private:
	std::string name;
	Weapon weapon;
	HumanB();
};
