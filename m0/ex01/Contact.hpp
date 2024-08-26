/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:49:39 by orezek            #+#    #+#             */
/*   Updated: 2024/08/26 21:42:01 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>

class Contact
{
	public:
	Contact();
	Contact(std::string f_name, std:: string l_name, std:: string nicname, std:: string phone, std:: string secret);
	~Contact();
	void			SetFname(std::string f_name);
	std::string		GetFname(void) const;

	void			SetLname(std::string l_name);
	std::string		GetLname(void) const;

	void			SetNicname(std:: string nicname);
	std::string		GetNicname(void) const;

	void			SetPhone(std:: string phone);
	std:: string	GetPhone(void) const;

	void			SetSecret(std:: string secret);
	std:: string	GetSecret(void) const;

	void			SetId(int id);
	int				GetId(void) const;

	private:
	std:: string	f_name;
	std:: string	l_name;
	std:: string	nicname;
	std:: string	phone;
	std:: string	secret;
	int				id;
};
