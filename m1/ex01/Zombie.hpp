/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:13:34 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 10:29:51 by orezek           ###   ########.fr       */
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
	Zombie(){};
	Zombie(std::string name);
	~Zombie(void);
	void	setName(std:: string name);
	void	announce(void);

	private:
	std::string name;
};
// Global functions decleration
Zombie* zombieHorde( int N, std::string name );
