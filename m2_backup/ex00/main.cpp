/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:30:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/11 11:15:03 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Why cannocical orthodox way? cpp compiler does not handle
// these operations by default well. It creates shadow copies
// i.e copies pointers (memory addresses) not actual bytes

int main( void )
{
	Fixed obj; // default constructor
	Fixed cpObj(obj); // copy constructor - creates a copy of obj object
	Fixed anotherObj; // default constructor
	anotherObj = cpObj; // assignment operator overloaded by
	// test
	//obj.setRawBits(34);
	std::cout << obj.getRawBits() << std::endl;
	std::cout << cpObj.getRawBits() << std::endl;
	std::cout << anotherObj.getRawBits() << std::endl;

	return 0;
}
