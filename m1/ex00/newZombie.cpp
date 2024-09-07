/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:43:37 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 08:45:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Globel function accessible from all the files from the project
	the returned object has to be manually deleted by delete keyword
	object created in heap memory
*/
Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}
