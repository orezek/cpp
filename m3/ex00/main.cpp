/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:03:58 by orezek            #+#    #+#             */
/*   Updated: 2024/09/13 11:47:06 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ct1 = ClapTrap("Joseph");
	ClapTrap ct2("Petr"); // alternate object creation
	ClapTrap ct3;
	ClapTrap ct4;
	ClapTrap ct5("Jannete");
	ct3 = ClapTrap(ct1); // copy constructor
	ct4 = ct3; // copy assignment operator
	ct4 = ClapTrap(ct5);

	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getHitPoints());

// not printing anything
	ct3.getName();
	ct4.getName();

// Some other tests
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Some more tests" << std::endl;
	ClapTrap ct10("Vasek");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << ct10.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << ct10.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ct10.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ct10.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;

	ct10.attack("Evaluator");
	ct10.takeDamage(4);
	ct10.beRepaired(2);

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << ct10.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << ct10.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ct10.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ct10.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;


	ct10.takeDamage(10);
	ct10.takeDamage(10);
	ct10.beRepaired(2);
	ct10.beRepaired(2);

	for (int i = 0; i < 9; i++)
		ct10.attack("Evaluator");
	ct10.beRepaired(2);

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << ct10.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << ct10.getHitPoints() << std::endl;
	std::cout << "Energy points: " << ct10.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << ct10.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	return (0);
}


/*
Line 22 explained
In this line, the expression ClapTrap(ct1) creates a temporary object by invoking the
copy constructor.
This temporary object is immediately assigned to ct3 using the assignment operator.
After the assignment is complete, the temporary object (the copy of ct1) is destroyed because
it has no name and only exists for the duration of the assignment statement.
*/
