/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:35:47 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 13:19:15 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

namespace Utils
{
	std::string GetInput(const std::string& prompt)
	{
		std::string input;
		while (true)
		{
			std::cout << prompt << std::endl;
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(1);
			if (std::cin.fail())
			{
				std::cout << "Input error! Please try again." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			if (input.empty())
			{
				std::cout << "Field was empty! Try again." << std::endl;
				continue;
			}
			else
			{
				return input;
			}
		}
	}

	std::string	GetNumericInput(const std::string &prompt)
	{
		std::string	input;
		while (true)
		{
			std::cout << prompt << std::endl;
			std::getline(std::cin, input);
			if (std::cin.fail())
			{
				std::cout << "Input error! Please try again." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			if (input.empty())
			{
				std::cout << "Field was empty! Try again." << std::endl;
				continue;
			}
			if (!IsPhoneNumberValid(input))
			{
				std::cout << "Invalid Phone Number:  +(contry_code)(local_number)." << std::endl;
				continue;
			}
			else
			{
				return input;
			}
		}
	}

	bool	IsPhoneNumberValid(const std::string &phone)
	{
		for (int i = 0; i < (int) phone.length(); i++)
		{
			if (phone[i] == '+')
			{
				if (i != 0)
					return (false);
				continue;
			}
			if (phone[i] >= '0' && phone[i] <= '9')
				continue;
			else
				return (false);
		}
		return (true);
	}

	std::string	TrancStr(const std::string &str)
	{
		if (str.length() > 9)
			return (str.substr(0, 9) + '.');
		return (str);
	}
}
