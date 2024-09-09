/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:29:27 by orezek            #+#    #+#             */
/*   Updated: 2024/09/09 12:40:49 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl()
{
	// Initializing the member function pointer array in the constructor
	functionPtr[0] = &Harl::debug;
	functionPtr[1] = &Harl::info;
	functionPtr[2] = &Harl::warning;
	functionPtr[3] = &Harl::error;
};
// Destructor
Harl::~Harl() {};
// Private methods for printing the messages
void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger!";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public method that calles the private methods.
void Harl:: complain(const std::string level)
{
	// Array of level messages - the order has to match with function pointer array!
	std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// // searching for Harl message and calling appropriate function
	for (int i = 0; i < NO_PTR; i++)
	{
		if(level == levelArray[i])
		{
			switch (i)
			{
				case 0:
					(this->*functionPtr[0])();
					(this->*functionPtr[1])();
					(this->*functionPtr[2])();
					(this->*functionPtr[3])();
					break;
				case 1:
					(this->*functionPtr[1])();
					(this->*functionPtr[2])();
					(this->*functionPtr[3])();
					break;
				case 2:
					(this->*functionPtr[2])();
					(this->*functionPtr[3])();
					break;
				case 3:
					(this->*functionPtr[3])();
					break;
				default:
					break;
			}
			break;
		}
	}
}
