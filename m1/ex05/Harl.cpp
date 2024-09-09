/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:47 by orezek            #+#    #+#             */
/*   Updated: 2024/09/09 12:14:51 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl()
{
	// Initializing the member function pointer array in the constructor
	functionPtr[0] = &Harl::debug;
	functionPtr[1] = &Harl::info;
	functionPtr[2] = &Harl::warning;
	functionPtr[3] = &Harl::error;
};
// Destructor
Harl::~Harl() {};
// Private methods for printing the messages
void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger!";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public method that calles the private methods.
void Harl:: complain(const std::string level)
{
	// Array of level messages - the order has to match with function pointer array!
	std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// // searching for Harl message and calling appropriate function
	for (int i = 0; i < NO_PTR; i++)
	{
		if(level == levelArray[i])
		{
			(this->*functionPtr[i])();
			break;
		}
	}
}


/*
	// Anothor option how to define function pointer, you can define inside complain method (M.B option)
	// better option is to define the function pointer array in the header and use constructor
	// to assing the function pointers to that array
	//------------------------------------------------
	// // Function pointers
	// // debug
	// void (Harl::*debugPtr)(void) = &Harl::debug;
	// // info
	// void (Harl::*infoPtr)(void) = &Harl::info;
	// // warning
	// void (Harl::*warningPtr)(void) = &Harl::warning;
	// // error
	// void (Harl::*errorPtr)(void) = &Harl::error;
	// // Array of function pointers
	// void (Harl::*functionPtr[4])(void) = {debugPtr, infoPtr, warningPtr, errorPtr};
	//-------------------------------------------------------------------------------


Reasons for declaring the function pointer array in the header file again declaring it in the function complain.
The more professional and maintainable version of the code is the one where the function pointer array is defined as a private member in the class header and initialized in the constructor. Here's why:

1. Encapsulation and Separation of Concerns:
Professional Code values encapsulation. Declaring the function pointer array in the class header file keeps the implementation clean and encapsulated, which adheres to Object-Oriented Programming (OOP) principles.
The version with the pointer array in the class header keeps the internal workings of the Harl class hidden from users of the class, which is good design.
2. Initialization Logic:
Initializing the function pointer array in the constructor allows you to centralize the initialization logic. This is more flexible because the constructor is where all initial setup should be done. If the function pointer array ever needs to be changed or extended, the changes would be easier to manage in the constructor rather than scattering initialization code inside multiple methods.
It also makes the code easier to modify later. If you decide to extend or alter the functionality, changes to the function pointer array can be easily managed in one place (the constructor).
3. Code Readability and Maintainability:
Having the function pointer array as part of the class makes the code easier to read because the class's responsibilities are clearer. Readers can quickly see what the class can do (via function pointers) and how it handles different levels.
If you define and initialize the function pointer array inside each function (as done in the version where it’s defined locally in complain()), the code can quickly become repetitive and harder to maintain. By centralizing initialization in the constructor, the overall design becomes cleaner and more maintainable.
4. Memory Efficiency:
While the difference is small, defining the function pointer array as a class member ensures that the array is allocated once for the lifetime of the object, rather than re-declaring and re-allocating the array every time the complain() function is called.
In the version where you declare the function pointer array inside complain(), you are allocating and initializing the array every time complain() is called, which is inefficient, especially for larger applications.
5. Extensibility:
If in the future you want to extend the Harl class (e.g., add more complaint levels), managing the function pointer array as a class member makes it much easier to extend functionality without modifying the complain() method itself. You just need to add a new function pointer to the array and extend the logic accordingly.
6. Code Reusability:
The function pointer array being part of the class allows the array to be used or accessed from other methods within the class if needed. This makes the class more modular and reusable. If you keep it inside a single function like complain(), you reduce flexibility and reusability.

*/
