/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:03:56 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 13:37:22 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPoint(0){}

// Int Constructor
Fixed::Fixed(const int intNumber) {
	_fixedPoint = intNumber << BITS;
}

// Float Constructor
Fixed::Fixed(const float floatNumber) {
	_fixedPoint = roundf(floatNumber * (float) (1 << BITS));
}

// Copy constructor takes a reference of a object
Fixed::Fixed(const Fixed &other)
{
	this->_fixedPoint = other.getRawBits();
}
// Copy Assignment operator overloading for Fixed object
Fixed &Fixed::operator=(const Fixed &other)
{
	if(this != &other)
		_fixedPoint = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(){}

int	Fixed::getRawBits() const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const {
	float floatNumber;

	floatNumber = (float)_fixedPoint / (float) (1 << BITS);
	return (floatNumber);
}

int	Fixed::toInt (void) const {
	return (_fixedPoint >> BITS);
}

// Now you're talking part
// < operator overloading
bool Fixed::operator>(const Fixed &valB) const
{
	return (this->getRawBits() > valB.getRawBits());
}
// > operator overloading
bool Fixed::operator<(const Fixed &valB) const
{
	return (this->getRawBits() < valB.getRawBits());
}

bool Fixed::operator<=(const Fixed &valB) const
{
	return (this->getRawBits() <= valB.getRawBits());
}

bool Fixed::operator>=(const Fixed &valB) const
{
	return (this->getRawBits()>= valB.getRawBits());
}

bool	Fixed::operator==(const Fixed &valB) const {
	return (this->getRawBits() == valB.getRawBits());
}

bool	Fixed::operator!=(const Fixed &valB) const {
	return (this->getRawBits() != valB.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &valB) const {
	Fixed temp;

	temp.setRawBits((this->getRawBits() + valB.getRawBits()));
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &valB) const {
	Fixed temp;

	temp.setRawBits((this->getRawBits() - valB.getRawBits()));
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &valB) const {
	Fixed temp;
	temp.setRawBits(((long long)this->getRawBits() * (long long)valB.getRawBits()) >> BITS);
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &valB) const {
	Fixed temp;
	temp.setRawBits(((long long)this->getRawBits() << BITS) / valB.getRawBits());
	return (temp);
}


Fixed&	Fixed::operator++() {
	_fixedPoint++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed preFixed = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (preFixed);
}

Fixed	Fixed::operator--(int) {
	Fixed preFixed = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (preFixed);
}

Fixed&	Fixed::min(Fixed &valA, Fixed &valB) {
	if (valA <= valB)
		return (valA);
	return (valB);
}

const Fixed	&Fixed::min(const Fixed &valA, const Fixed &valB) {
	if (valA <= valB)
		return (valA);
	return (valB);
}

Fixed	&Fixed::max(Fixed &valA, Fixed &valB) {
	if (valA >= valB)
		return (valA);
	return (valB);
}

const Fixed	&Fixed::max(const Fixed &valA, const Fixed &valB) {
	if (valA >= valB)
		return (valA);
	return (valB);

}

// this obejct is outside of the class Fixed()
std::ostream	&operator<<(std::ostream &outputStream, const Fixed &fixedNb)
{
	outputStream << fixedNb.toFloat();
	return (outputStream);
}
