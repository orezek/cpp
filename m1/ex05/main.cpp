/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:29:14 by orezek            #+#    #+#             */
/*   Updated: 2024/09/09 12:20:35 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harlObj;
	std::cout << std::endl;
	std::cout << "DEBUG: ";
	harlObj.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "INFO: ";
	harlObj.complain("INFO");
	std::cout << std::endl;
	std::cout << "WARNING: ";
	harlObj.complain("WARNING");
	std::cout << std::endl;
	std::cout << "ERROR: ";
	harlObj.complain("ERROR");
	return (0);
}
