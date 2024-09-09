/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:21:46 by orezek            #+#    #+#             */
/*   Updated: 2024/09/09 12:01:19 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define NO_PTR 4
class Harl
{
	public:
	Harl();
	~Harl();
	void complain( std::string level );

	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (Harl::*functionPtr[NO_PTR])(void);
};
