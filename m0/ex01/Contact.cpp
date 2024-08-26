/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:00:41 by orezek            #+#    #+#             */
/*   Updated: 2024/08/26 21:42:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact() : f_name(""), l_name(""), nicname(""), phone(""), secret(""), id(-1){};

Contact::Contact(
	std::string f_name,
	std:: string l_name,
	std:: string nicname,
	std:: string phone,
	std:: string secret) :
		f_name(f_name),
		l_name(l_name),
		nicname(nicname),
		phone(phone),
		secret(secret) {};

Contact::~Contact() {};

std::string Contact::GetFname(void) const
{
	return this->f_name;
}

void Contact::SetFname(std::string f_name)
{
	this->f_name = f_name;
}

std::string Contact::GetLname(void) const
{
	return this->l_name;
}

void Contact::SetLname(std::string l_name)
{
	this->l_name = l_name;
}

std::string Contact::GetNicname(void) const
{
	return this->nicname;
}

void Contact::SetNicname(std:: string nicname)
{
	this->nicname = nicname;
}

std:: string Contact::GetPhone(void) const
{
	return (this->phone);
}

void Contact::SetPhone(std::string phone)
{
	this->phone = phone;
}

std::string Contact::GetSecret(void) const
{
	return (this->secret);
}

void Contact::SetSecret(std::string secret)
{
	this->secret = secret;
}

int Contact::GetId(void) const
{
	return (this->id);
}

void Contact::SetId(int id)
{
	this->id = id;
}

