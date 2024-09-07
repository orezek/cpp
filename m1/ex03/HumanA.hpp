/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:25:49 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:57:34 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(std::string name, Weapon weapon);
	void attack(void);

	private:
	std::string name;
	Weapon weapon;
	HumanA();
};
