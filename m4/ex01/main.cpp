/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:40:28 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 14:44:01 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// 1. Polymorphism Test
	std::cout << "=== Polymorphism Test ===" << std::endl;

	const Animal* animals[4];  // Array of Animal pointers
	animals[0] = new Dog();  // Animal pointer pointing to a Dog object
	animals[1] = new Cat();  // Animal pointer pointing to a Cat object
	animals[2] = new Dog();
	animals[3] = new Cat();

	// Loop over the array and call makeSound() polymorphically
	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}

	// Clean up dynamically allocated memory
	for (int i = 0; i < 4; i++) {
		delete animals[i];  // This will call the correct destructor due to virtual destructor
	}

	std::cout << "=== End of Polymorphism Test ===\n" << std::endl;

	// 2. Deep Copy Test
	std::cout << "=== Deep Copy Test ===" << std::endl;

	Dog originalDog;
	originalDog.makeSound();  // Check the original dog sound

	// Deep copy the originalDog
	Dog copiedDog(originalDog);  // Calls copy constructor
	copiedDog.makeSound();

	// Modify the Brain of the copied dog (this will show that the deep copy works)
	std::cout << "Modifying copied dog's brain" << std::endl;
	copiedDog = originalDog;  // Calls assignment operator

	std::cout << "=== End of Deep Copy Test ===\n" << std::endl;

	// 3. Assignment Operator Test
	std::cout << "=== Assignment Operator Test ===" << std::endl;

	Cat originalCat;
	originalCat.makeSound();

	Cat anotherCat;
	anotherCat = originalCat;  // Calls the assignment operator

	anotherCat.makeSound();  // Check if it makes the same sound

	std::cout << "=== End of Assignment Operator Test ===\n" << std::endl;

	// 4. Destructor Test
	std::cout << "=== Destructor Test ===" << std::endl;

	{
		Dog tempDog;
		tempDog.makeSound();
		// Dog will be destroyed here, destructor should be called
	}

	std::cout << "=== End of Destructor Test ===\n" << std::endl;
	// 42 Compulsory test
	std::cout << "=== 42 Compulsory Test ===" << std::endl;

	const int arraySize = 6;
	Animal* animalsArray[arraySize];

	// Fill half the array with Dogs, and the other half with Cats
	for (int i = 0; i < arraySize / 2; i++) {
		animalsArray[i] = new Dog();  // Dog objects
	}
	for (int i = arraySize / 2; i < arraySize; i++) {
		animalsArray[i] = new Cat();  // Cat objects
	}

	// Make each Animal make a sound to confirm they were created correctly
	std::cout << "=== Animals Making Sounds ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		animalsArray[i]->makeSound();
	}
	std::cout << "=== End of Sounds ===" << std::endl;

	// Delete each Animal, this should call the correct destructors
	std::cout << "=== Deleting Animals ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		delete animalsArray[i];  // Proper destructors for Dog and Cat will be called
	}
	std::cout << "=== All Animals Deleted ===" << std::endl;

	// Optional: Check for memory leaks using a tool like Valgrind
	// Valgrind command: valgrind --leak-check=full ./bin/program_name
	std::cout << "=== End of 42 Compulsory Test ===\n" << std::endl;

	// Another TEST

	Dog origDog;
	Cat origCat;

	// Set ideas for orig Dog and Cat
	origDog.setIdea(0, "Chase the ball");
	origDog.setIdea(1, "Bark at the mailman");
	origCat.setIdea(0, "Sleep on the couch");
	origCat.setIdea(1, "Scratch the furniture");

	// Display initial ideas
	std::cout << "\n=== Orig Dog Ideas ===" << std::endl;
	origDog.printIdeas(2);
	origDog.displayBrainAddress();

	std::cout << "\n=== Orig Cat Ideas ===" << std::endl;
	origCat.printIdeas(2);
	origCat.displayBrainAddress();

	// Deep copy the Dog and Cat
	std::cout << "\n=== Copying Dog and Cat ===" << std::endl;
	Dog cpDog(origDog);  // Calls copy constructor
	Cat cpCat(origCat);  // Calls copy constructor

	// Display cp Dog and Cat's ideas and brain addresses
	std::cout << "\n=== Cp Dog Ideas ===" << std::endl;
	cpDog.printIdeas(2);
	cpDog.displayBrainAddress();  // Should be different from origDog's

	std::cout << "\n=== Cp Cat Ideas ===" << std::endl;
	cpCat.printIdeas(2);
	cpCat.displayBrainAddress();  // Should be different from origCat's

	// Modify the Cp Dog's Brain
	std::cout << "\n=== Modifying Cp Dog's Brain ===" << std::endl;
	cpDog.setIdea(0, "Dig a hole in the yard");
	cpDog.printIdeas(2);  // Show new idea in cp dog

	std::cout << "\n=== Orig Dog's Ideas After Modification ===" << std::endl;
	origDog.printIdeas(2);  // Orig Dog's ideas should remain unchanged

	// Test with Animal* polymorphism
	std::cout << "\n=== Polymorphism Test with Animal* ===" << std::endl;
	Animal* animals1[2];
	animals1[0] = new Dog();
	animals1[1] = new Cat();

	animals1[0]->makeSound();  // Should call Dog's makeSound
	animals1[1]->makeSound();  // Should call Cat's makeSound

	// Clean up Animal pointers
	delete animals1[0];
	delete animals1[1];
	std::cout << "=== END - Polymorphism Test with Animal* ===\n" << std::endl;
	return 0;
}


/*
Why Does This Work?
This works because of the is-a relationship that exists
between a base class and its derived classes in C++.

When you define Dog or Cat as a derived class of Animal,
you are stating that both Dog and Cat are types of Animal.
As a result, a pointer to Animal can hold a pointer to any derived
class object (such as Dog or Cat). This is called upcasting because you are
"casting" or treating a derived class object as though it were a base class object.
In simpler terms, since every Dog and Cat is an Animal, it is valid to treat them
as such, which is why you can store a Dog or Cat object in a pointer to Animal.

What About Virtual Functions and Polymorphism?
The real power of polymorphism comes when you use virtual functions in the base
class (Animal). This allows you to call functions on a base class pointer (Animal*),
but the actual function that gets called is the one defined in the derived class (Dog or Cat).

For example, if Animal has a virtual void makeSound() function that is overridden
in Dog and Cat, calling makeSound() on the base class pointer will invoke the
correct version depending on the actual object type (either Dog or Cat).
*/
