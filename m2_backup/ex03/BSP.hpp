/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:53:01 by orezek            #+#    #+#             */
/*   Updated: 2024/09/12 10:53:07 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"
#include "Point.hpp"

Fixed crossSectionOrientation(const Point &pointA, const Point &pointB, const Point &pointToCheck);
bool bsp( Point const a, Point const b, Point const c, Point const point);
