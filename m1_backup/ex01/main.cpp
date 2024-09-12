/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:30:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 12:18:46 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Point of this exercise:
// Overloading << operator
// Understanding fixed point numbers and using the Fixed class
// << [stream insertion operator] by default can work with strings and other data types
// The construcotrs take varius number types and inernally convert it into fixed point number
// by number * 2^BITS || (1<<BITS) and then converting it to int or float by the class
// member functions functions
#include <iostream>
int main( void )
{
	Fixed a;
	Fixed const b(512);
	Fixed const c(42.42f);
	Fixed const d(b); // copies the content of b to d (copy constructor)
	a = Fixed(1234.4321f); // Float constructor is assigned to a. Prev object a is deleted and new object a is created

	// prints default constructor messages
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	// converts a,b,c to int
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// example - watch Fixed const b(512);
	std::cout << "d is " << d.getRawBits() << " as integer represented in Fixed Point representation" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	// Testing objects mem. addresses - each refer to a different address
	std::cout << "Address of a: " << &a << std::endl;
	std::cout << "Address of b: " << &b << std::endl;
	std::cout << "Address of c: " << &c << std::endl;
	std::cout << "Address of d: " << &d << std::endl;
	return (0);
}
