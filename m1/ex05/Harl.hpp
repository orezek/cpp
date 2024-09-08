/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:21:46 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 16:33:51 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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
}
