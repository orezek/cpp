/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:30:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/11 20:07:05 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Point of this exercise:
// Overloading << operator
// Understanding fixed point number
// << [stream insertion operator] by default can work with strings and other data types

#include <iostream>
int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b ); // copies the content of b to d (copy constructor)
	a = Fixed( 1234.4321f ); // Float constructor is assigned to a. Prev object a is deleted and new object a is created

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// Testing objects mem addresses
	std::cout << "Address of a: " << &a << std::endl;
	std::cout << "Address of b: " << &b << std::endl;
	std::cout << "Address of c: " << &c << std::endl;
	std::cout << "Address of d: " << &d << std::endl;
	return (0);
}
