/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:02:04 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 11:28:38 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

/*
	All the various types of constructos are example of
	POLYMORPHISM!
	Fixed point numbers are representation of some other type of number in way that the fixed point
	number is divided into its whole component and its fractional part.
	For example Fixed Point number 512 is in float terms 2.0 given 8 bits (BITS) are reserved for the fractional part.
*/
class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();
		Fixed(const int val);
		Fixed(const float val);
		// Get and Set _fixedPoint
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int _fixedPoint;
		static const int BITS = 8;

};
std::ostream &operator<<(std::ostream &outputStream, const Fixed &fixedNb);

