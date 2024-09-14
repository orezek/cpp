/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:40:28 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 15:30:22 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Point of the exercises: Polymorphism (virtual), Deep momory vs shallow memory copying, Using Abstruct classes

int main(void)
{
	// Constructor testing
	// Animal test
	std::cout << "Animal constructors called:" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Animal anim1 = Animal(); // copy initialization
	Animal anim2;            // default initialization
	Animal anim3;            // same as above
	Animal anim4 = Animal(anim1); // copy constructor
	anim3 = anim2;                // assignment operator at work

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Cat constructors called:" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	// Cat test
	Cat cat1 = Cat();       // copy initialization
	Cat cat2;               // default initialization
	Cat cat3;               // same as above
	Cat cat4 = Cat(cat1);   // copy constructor
	cat3 = cat2;            // assignment operator at work

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Dog constructors called:" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	// Dog test
	Dog dog1 = Dog();       // copy initialization
	Dog dog2;               // default initialization
	Dog dog3;               // same as above
	Dog dog4 = Dog(dog1);   // copy constructor
	dog3 = dog2;            // assignment operator at work

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Object functions called:" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	// Object polymorphism testing
	Animal anim10;
	Cat cat10;
	Dog dog10;

	// Calling functions should have different stdout for each.
	std::cout << "Should print: Animals make sound -> ";
	anim10.makeSound();

	std::cout << "Should print: Cat makes mew ooh -> ";
	cat10.makeSound();

	std::cout << "Should print: Dog makes woof woof -> ";
	dog10.makeSound();


	std::cout << "---------------------------------" << std::endl;
	std::cout << "42 default tests:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Wrong Animal and Cat test" << std::endl;
	// Object polymorphism testing - it shoudl not work
	WrongAnimal wrongAnim10;
	WrongCat wrongCat10;

	// Calling functions should have different stdout for each.
	std::cout << "Should print: WrongAnimals make sound -> ";
	wrongAnim10.makeSound();

	std::cout << "Should print: WrongCat makes meow -> ";
	wrongCat10.makeSound();


	std::cout << "---------------------------------" << std::endl;
	std::cout << "Wrong Animal and Cat 42 default tests:" << std::endl;
	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();
	std::cout << iWrong->getType() << " " << std::endl;
	iWrong->makeSound(); //should not output the cat sound!
	metaWrong->makeSound();

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Implicit destructors will be called in reverse order of creation" << std::endl;
	// Object have to be manually deleted.
	delete meta;
	delete i;
	delete j;
	delete metaWrong;
	delete iWrong;
	return (0);
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

/*
Copy Initialization vs. Direct Initialization:

When you use Dog dog = Dog();, it's copy initialization because it involves creating a
temporary Dog object and then copying or moving it into the dog variable.
When you use Dog dog;, it’s direct initialization or default initialization,
where the object is created directly using the default constructor,
and no temporary object is involved.
Most Vexing Parse:

Dog dog(); looks like object initialization, but it's actually a
function declaration. This is a quirk in C++'s grammar, often called
the Most Vexing Parse. If you intend to create an object, you need to avoid this syntax.

*/
