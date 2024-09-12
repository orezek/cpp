/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:30:30 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 13:13:18 by orezek           ###   ########.fr       */
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
	Fixed a; // default constructor
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // copy constructor wit overloaded * operator
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}

/*
My output
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016

// 42 results
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016


*/
