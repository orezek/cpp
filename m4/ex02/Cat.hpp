/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:39:28 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 14:36:49 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &obj);
		~Cat();
		Cat &operator=(const Cat &obj);
		void makeSound(void) const;

		// Testing functions
		void displayBrainAddress() const;
		void printIdeas(int count) const;
		void setIdea(int index, const std::string &idea);

	private:
		Brain *_brain;
};
