/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:11:00 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 16:47:21 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
	{
		std::ostringstream oss;
		oss << i;
		ideas[i] = "idea "+ oss.str();
	}
	std::cout << "Brain was created by default constructor." << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Brain was created by copy constructor." << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	std::cout << "Brain was assigned by assignment operator." << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed by destructor." << std::endl;
};

// Testing functions implementation
void Brain::printIdeas(int count) const
{
	for (int i = 0; i < count && i < 100; i++)
		std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}
