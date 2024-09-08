/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:58:50 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 13:20:04 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0), contactCounter(0) {};

PhoneBook::~PhoneBook() {};

bool	PhoneBook::AddContact(void)
{
	Contact new_contact = Contact();
	new_contact.SetFname(Utils::GetInput("Enter First Name:"));
	new_contact.SetLname(Utils::GetInput("Enter Last Name:"));
	new_contact.SetNicname(Utils::GetInput("Enter Nicname:"));
	new_contact.SetPhone(Utils::GetNumericInput("Enter Phone Number:"));
	new_contact.SetSecret(Utils::GetInput("Enter the Darkest Secret:"));
	return (InsertContact(new_contact) == 1);
};

int	PhoneBook::InsertContact(Contact &new_contact)
{
	new_contact.SetId(++contactCounter);
	if (currentSize < MAX_CONTACTS)
	{
		contacts[currentSize % MAX_CONTACTS] = new_contact;
		++currentSize;
	}
	else
	{
		contacts[oldestIndex] = new_contact;
		oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
	}
	return (1);
}

const Contact*	PhoneBook::SearchContact(void) const
{
	std::string	idInput;
	int			foundIndex;
	int			index;
	while(true)
	{
		idInput = Utils::GetInput("Insert Index ID (1 - 8) or type END to return to the MAIN MENU");
		if (idInput == ESCAPE_INDEX)
			break;
		std::istringstream ss(idInput);
		ss >> index;
		if (ss.fail() || !ss.eof())
		{
			std::cout << "Contact not found, use correct INDEX number." << std::endl;
			continue;
		}
		foundIndex = FindIndex(index);
		if (foundIndex == INVALID_INDEX)
			std::cout << "Contact not found, use correct INDEX number." << std::endl;
		else
			return (&contacts[foundIndex]);
	}
	return (NULL);
}

int PhoneBook::FindIndex(int index) const
{
	if (index > 0 && contactCounter >= index && index <= MAX_CONTACTS)
		return (index - 1);
	else
		return (INVALID_INDEX);
}

void	PhoneBook::PrintContact(const Contact *contact) const
{
	if (contact != NULL)
	{
		std::cout << std::endl;
		std::cout << "---------Printing Contact Details-----------" << std::endl;
		std::cout << std::endl;
		std::cout << "First name: " << contact->GetFname() << std::endl;
		std::cout << "Last name: " << contact->GetLname() << std::endl;
		std::cout << "Nickname: " << contact->GetNicname() << std::endl;
		std::cout << "Phone number: " << contact->GetPhone() << std::endl;
		std::cout << "Darkest secret: " << contact->GetSecret() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void	PhoneBook::PrintAllContacts(void) const
{
	std::cout << std::endl;
	std::cout << "--------------Printing Contacts--------------" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].GetId() == -1)
			continue;
		std::cout << "|" << std::setw(10) << std::right << contacts[i].GetId() << "|"
					<< std::setw(10) << std::right << Utils::TrancStr(contacts[i].GetFname()) << "|"
					<< std::setw(10) << std::right << Utils::TrancStr(contacts[i].GetLname()) << "|"
					<< std::setw(10) << std::right << Utils::TrancStr(contacts[i].GetNicname()) << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}
