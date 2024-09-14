/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:47:26 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 14:35:16 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &obj);
		~Dog();
		Dog &operator=(const Dog &obj);
		void makeSound(void) const;

		// Testing functions
		void displayBrainAddress() const;  // Renamed function to display brain address
		void printIdeas(int count) const;  // Print Dog's ideas
		void setIdea(int index, const std::string &idea);
	private:
		Brain *_brain;
};
