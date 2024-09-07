/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:01:06 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 16:12:28 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
Why reference for A and pointer for B?

I could have used pointers for both bot not reference for both.

Reference needs to have existing object to refer to - Hence HumanB needs to use pointer
becuase pointer can be NULL. HumanB may or may not have a weapon = pointer.
HumanA has always weapon hence Weapon object is craeted before HumanA is created and then passed
to it. HumanA could have pointer as well but since the main method is provided as "is"
it is not possible to change the reference type in the constructor Weapon() to pointer.

As for HumanB setWeapon() it takes also reference as argument not a pointer *.

Summary: The main method forces you to use references as arguments. Since reference
needs to have an existing object, only HumanA can be used with reference to Weapon.
HumanB may or may not use Weapon() object hence pointer type is more suitable for
HumanB. In HumanB the setWeapon() is set to use reference as can be seen in the line 49.
*/

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
