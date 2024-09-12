/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:49:50 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 14:20:28 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {

public:
// Orthodox canonical form
	Point();
	// Copy constructor
	Point(const Point&);
	// non default constructor
	Point(const float newX, const float newY);
	// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
	Point &operator=(const Point&);
	// destructor
	~Point();
	const Fixed	&getX() const;
	const Fixed	&getY() const;

private:
	Fixed const x;
	Fixed const y;
};

std::ostream	&operator<<(std::ostream &outputStream, const Point &point);
