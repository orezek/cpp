/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:42:23 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 08:45:46 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	the object has been created in stack
	it will be automatically deleted when the function is out of scope
*/
void randomChump(std::string name)
{
	Zombie obj =  Zombie(name);
	obj.announce();
}
