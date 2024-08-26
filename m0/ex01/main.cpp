/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:59:37 by orezek            #+#    #+#             */
/*   Updated: 2024/08/26 21:51:42 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>

int	main(void)
{
	std::string	input;
	PhoneBook	phoneBook;

	while (true)
	{
		std::cout << "********************************************" << std::endl;
		std::cout << "***********PHONE BOOK FROM THE 80s**********" << std::endl;
		std::cout << "********************************************" << std::endl;
		input = Utils::GetInput("Enter ADD, SEARCH or EXIT to continue");
		if (input == "ADD")
		{
			if (phoneBook.AddContact() == true)
				std::cout << "Contact Added Successfuly." << std::endl;
			else
				std::cout << "Adding the contact failed." << std::endl;
		}
		else if (input == "SEARCH")
		{
			phoneBook.PrintAllContacts();
			phoneBook.PrintContact(phoneBook.SearchContact());
		}
		else if (input == "EXIT")
		{
			std::cout << "Program exited" << std::endl;
			return (0);
		}
		else
			std::cout << "Ivalid Input, type ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
