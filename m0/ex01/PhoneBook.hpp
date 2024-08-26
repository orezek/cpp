/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:50:32 by orezek            #+#    #+#             */
/*   Updated: 2024/08/26 21:36:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iomanip>
#include <limits>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include "Utils.hpp"

const int	MAX_CONTACTS = 8;
const int	INVALID_INDEX = -99;
const		std::string ESCAPE_INDEX = "END";

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	bool			AddContact(void);
	const Contact*	SearchContact(void) const;
	void			PrintAllContacts(void) const;
	void			PrintContact(const Contact *contact) const;

	private:
	int				InsertContact(Contact &contact);
	int				FindIndex(const int index) const;
	Contact			contacts[MAX_CONTACTS];
	int				currentSize;
	int				oldestIndex;
	int				contactCounter;
};
#endif
