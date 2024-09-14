/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:46:03 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 15:09:33 by orezek           ###   ########.fr       */
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

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
	protected:
		std::string _type;
};


/*
Animal class non-instantiable, you can convert it into an abstract base class.
In C++, abstract base classes are classes that cannot be instantiated directly,
but they can still be inherited by other classes.
To make a class abstract, you declare at least one pure virtual function in the class.

What is a Pure Virtual Function?
A pure virtual function is a function that must be overridden in any derived class,
and it makes the class abstract. This means that you cannot create an
object of this class directly, but you can create objects of derived
classes that implement the pure virtual functions.

In your case, the Animal class should become abstract because it doesn't make sense
to create an object of Animal—only its derived classes like Dog and Cat make sense as real objects.

How to Implement the Change:
Make Animal an abstract class by adding a pure virtual function.

The simplest way is to make the makeSound() function a pure virtual function. Since Animal doesn't
make a sound, it should delegate this responsibility to the derived classes (Dog, Cat).
*/
