/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:02:41 by orezek            #+#    #+#             */
/*   Updated: 2024/09/07 13:21:06 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class Weapon
{
	public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string	getType(void) const;
	void		setType(std::string newType);

	private:
	Weapon();
	std::string type;
};
