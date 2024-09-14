/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:40:28 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 15:17:06 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main() {
	// 1. Attempt to instantiate Animal (should not compile)
	//Animal animal;  // Uncommenting this line will cause a compilation error because Animal is abstract

	// 2. Create an array of Animal* pointers, half Dog and half Cat
	const int arraySize = 4;
	Animal* animals[arraySize];

	animals[0] = new Dog();  // Polymorphic behavior
	animals[1] = new Cat();  // Polymorphic behavior
	animals[2] = new Dog();
	animals[3] = new Cat();

	// 3. Call makeSound() polymorphically
	std::cout << "\n=== Polymorphism Test ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		animals[i]->makeSound();  // Calls makeSound() for Dog or Cat
	}

	// 4. Test Deep Copy
	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	Dog origDog;
	origDog.setIdea(0, "Chase the ball");
	origDog.setIdea(1, "Bark at the mailman");

	std::cout << "\nOrig Dog Ideas Before Copying:" << std::endl;
	origDog.printIdeas(2);
	origDog.displayBrainAddress();

	// Create a copy of origDog
	Dog cpDog(origDog);  // Calls copy constructor

	std::cout << "\nCp Dog Ideas After Copying:" << std::endl;
	cpDog.printIdeas(2);
	cpDog.displayBrainAddress();  // Memory address should be different from origDog

	// Modify cpDog's brain and ensure origDog is not affected
	cpDog.setIdea(0, "Dig a hole in the yard");

	std::cout << "\nOrig Dog Ideas After Cp Dog Modified:" << std::endl;
	origDog.printIdeas(2);  // Should remain unchanged
	std::cout << "\nCp Dog Ideas After Modification:" << std::endl;
	cpDog.printIdeas(2);  // First idea should now be "Dig a hole in the yard"

	// 5. Clean up the animals array
	std::cout << "\n=== Destructor Test ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		delete animals[i];  // Deletes Dog and Cat objects, calls destructors
	}

	return 0;
}

