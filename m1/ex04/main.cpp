/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:31:44 by orezek            #+#    #+#             */
/*   Updated: 2024/09/09 19:04:26 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream>

/*
	Main purpose of this exercie is to use ifstream and outstream API
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

// Checks if file is empty.
bool isFileEmpty(const std::string &filename)
{
	std::ifstream file(filename.c_str());  // Use .c_str() for C++98 compatibility
	// Move to the end of the file to check its size
	file.seekg(0, std::ios::end);
	bool isEmpty = file.tellg() == 0;
	// Move the file pointer back to the beginning for further I/O
	file.seekg(0, std::ios::beg);
	return isEmpty;
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

		if (isFileEmpty(argv[1]) == 1)
		{
			std::cerr << "ERROR: File is empty" << std::endl;
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
		std::ofstream outputFile(outputName.c_str());
		//std::ofstream outputFile(outputName); // work on MacOs not on linux -above line needed
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
