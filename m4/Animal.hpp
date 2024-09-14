/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:46:03 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 10:44:44 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &obj);
		virtual ~Animal();
		Animal &operator=(const Animal &obj);

		virtual void makeSound(void) const;
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
