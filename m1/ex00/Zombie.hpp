/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:19:19 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 08:51:00 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <string>
#include <iostream>

// Class declaration
class Zombie
{
	public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);

	private:
	Zombie(){};
	std::string name;
};
// Global functions decleration
void	randomChump(std:: string name);
Zombie	*newZombie(std:: string name);
