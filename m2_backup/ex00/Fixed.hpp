/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:02:04 by orezek            #+#    #+#             */
/*   Updated: 2024/09/10 16:19:57 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	public:
		Fixed(/* args */);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int _fixedPoint;
		static const int BITS = 8;

};


/*
Historical Context
The "Orthodox Canonical Form" originated from a time in C++
history when manual resource management was critical, and
programmers had to deal with raw pointers and dynamically
allocated memory frequently. The term itself comes from the
"orthodox" or standard practices that C++ developers followed
to ensure that classes were safe and predictable when copying,
assigning, or destroying objects. It helps prevent resource
mismanagement and guarantees proper behavior when working
with dynamic memory.


1. Copy Constructor
The copy constructor is used to create a new object
as a copy of an existing object.
This is typically called in situations like:

When an object is passed by value to a function.
When an object is returned from a function by value.
When an object is explicitly copied using initialization syntax.




*/
