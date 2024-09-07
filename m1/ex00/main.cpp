/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:19:25 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 08:46:03 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Okamura;

	Okamura = newZombie("Okamura");
	Okamura->announce();

	randomChump("Biden");

	delete Okamura;

	return (0);
}
