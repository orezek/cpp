/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:46:03 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 11:09:54 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal();  // Not virtual since WrongAnimal is intended to be a non-polymorphic base class
		WrongAnimal &operator=(const WrongAnimal &obj);

		void makeSound(void) const;  // Not virtual, no polymorphism intended for WrongAnimal
		std::string getType(void) const;

	protected:
		std::string _type;
};


/*
Inheritance (One-Way): When a class derives from a base class,
the derived class gets a copy of the base class's public and
protected members (functions and variables). The derived class
can override base class methods if they are declared virtual
in the base class.

Polymorphism creates the illusion of two-way interaction because you can call overridden functions in a derived class through a base class pointer or reference.
*/
