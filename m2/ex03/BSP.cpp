/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:53:27 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 13:49:13 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSP.hpp"
// Binary space partitioning.

Fixed crossSectionOrientation(Point const &pointA, Point const &pointB, Point const &pointToCheck) {
	Fixed dx1 = pointToCheck.getX() - pointB.getX();
	Fixed dy1 = pointToCheck.getY() - pointB.getY();
	Fixed dx2 = pointA.getX() - pointB.getX();
	Fixed dy2 = pointA.getY() - pointB.getY();

	Fixed result((dx1 * dy2) - (dx2 * dy1));

	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed signAB;
	Fixed signBC;
	Fixed signCA;

	signAB = crossSectionOrientation(a, b, point);
	signBC = crossSectionOrientation(b, c, point);
	signCA = crossSectionOrientation(c, a, point);

	if (signAB > 0 && signBC > 0 && signCA > 0)
		return (true);
	else if (signAB < 0 && signBC < 0 && signCA < 0)
		return (true);
	else
		return (false);
}
