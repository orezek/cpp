/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:13:03 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 10:40:27 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zom;
	int N = 10;

	zom = zombieHorde(10, "Charlie");
	for (int i = 0; i < N; i++)
		zom->announce();
	delete[] zom;
	return (0);
}
