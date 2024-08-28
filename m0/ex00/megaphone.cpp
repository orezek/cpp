/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:00:37 by orezek            #+#    #+#             */
/*   Updated: 2024/08/28 21:44:15 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			std::string temp = *argv;
			for (int i = 0; i < (int)temp.length(); i++)
				std::cout << (char)std::toupper(temp[i]);
			argv++;
			std::cout << std::endl;
		}
	}
	return (0);
}
