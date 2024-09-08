/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:47 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 16:52:08 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::debug(void)
{

}
Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
	std::cout << "You didn’t put enough bacon in my burger!"
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}
Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
