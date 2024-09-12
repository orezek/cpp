/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:48:55 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 14:35:50 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Point.hpp>
#include <BSP.hpp>

int main( void ) {
	// these form a triangle
	const Point	a(0.,0.);
	const Point	b(0.,10.);
	const Point c(10.,0.);
	// these are points to be checked
	const Point P1(1,1);
	const Point P2(5,5);
	const Point P3(9,10);
	const Point P4(-5,5);
	const Point P5(0,0);

// use of ternary operators
// (bsp(a, c, b, P1) ? "in" : "out") "if true in else out"
	std::cout << "Different versions of triangle are generated by changing a,b and c values.";
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(a, c, b, P1) ? "inside" : "outside") << std::endl;
	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(a, b, c, P1) ? "inside" : "outside") << std::endl;
	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(c, a, b, P1) ? "inside" : "outside") << std::endl;
	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(c, b, a, P1) ? "inside" : "outside") << std::endl;
	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(b, c, a, P1) ? "inside" : "outside") << std::endl;
	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << "Given a=0,0 b=0,10 c=10,0 Point: P1 is ";
	std::cout << (bsp(b, a, c, P1) ? "inside" : "outside") << std::endl;
	std::cout << std::endl;

	std::cout << "P2, P3, P4, P5 inside triangle:" << std::endl;
	std::cout << "P2 is on edge -> should be OUT: " << (bsp(a, b, c, P2) ? "in" : "out") << std::endl;
	std::cout << "P3 should be out: " << (bsp(a, b, c, P3) ? "in" : "out") << std::endl;
	std::cout << "P4 should be out: " << (bsp(a, b, c, P4) ? "in" : "out") << std::endl;
	std::cout << "P5 is a vertex -> should be OUT: " << (bsp(a, b, c, P5) ? "in" : "out") << std::endl;

	return (0);
}
