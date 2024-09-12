/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:02:04 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 12:23:50 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

/*
	The point of this exercise is to overload a lot of
	operators to have class that behaves like build in class
	with fixed point numbers
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
		// Get or Set _fixedPoint = converted fixed point number
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		// Conversion functions for _fixedPoint
		float				toFloat(void) const;
		int					toInt(void) const;
		// Now we're talking Part - overloading various operators
		bool				operator>(const Fixed &valB) const;
		bool				operator<(const Fixed &valB) const;
		bool				operator>=(const Fixed &valB) const;
		bool				operator<=(const Fixed &valB) const;
		bool				operator==(const Fixed &valB) const;
		bool				operator!=(const Fixed &valB) const;
		Fixed				operator+(const Fixed &valB) const;
		Fixed				operator-(const Fixed &valB) const;
		Fixed				operator*(const Fixed &valB) const;
		Fixed				operator/(const Fixed &valB) const;
		Fixed				&operator++();
		Fixed				&operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);
		static Fixed		&min(Fixed &valA, Fixed &valB);
		static const Fixed	&min(const Fixed &valA, const Fixed &valB);
		static Fixed		&max(Fixed &valA, Fixed &valB);
		static const Fixed	&max(const Fixed &valA, const Fixed &valB);

	private:
		int					_fixedPoint;
		static const int	BITS = 8;

};
// function for overloading stream operator - not part of the Fixed object
std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb);

