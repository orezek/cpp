/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:31:44 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 00:22:57 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream>

/*
	Side NOTE: two patterns.
	One for using argv for input - like bash command
	Second for using input inside a loop like GNL - more interactive usage (using file descriptors)
*/

int	isPrintable(std::string str)
{
	for (int i = 0; i < (int) str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
		{
			std::cerr << "ERROR: Invalid file." << std::endl;
			return (1);
		}
		std::string searchStr = argv[2];
		if (searchStr.empty())
		{
			std::cerr << "ERROR: Search string cannot be empty" << std::endl;
			return (1);
		}
		if (!isPrintable(searchStr))
		{
			std::cerr << "ERROR: Search string contains non-printable chars" << std::endl;
			return (1);
		}
		std::string outputName = argv[1];
		outputName.append(".replace");
		std::ofstream outputFile(outputName);
		if (!outputFile.is_open())
		{
			std::cerr << "Error: Could not create output file" << std::endl;
			inputFile.close();
			return (1);
		}
		std::string line;
		std::string replaceStr = argv[3];
		while (std::getline(inputFile, line))
		{
			size_t pos = line.find(searchStr);
			while (pos != std::string::npos) // npos is the largest possible value of size_t is constant
			{
				line.erase(pos, searchStr.length()); // Remove searchStr
				line.insert(pos, replaceStr); // Insert replaceWord
				pos = line.find(searchStr, pos + replaceStr.length()); // Continue searching after replacement
			}
			outputFile << line << '\n'; // Write modified line to output file
		}
		inputFile.close();
		outputFile.close();
	}
	else
	{
		std::cout << "Invalid input! Insert <file_name> <str_to_find> <str_to_replace>" << std::endl;
		return (1);
	}
	return (0);
}
