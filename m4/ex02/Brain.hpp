/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:06:20 by orezek            #+#    #+#             */
/*   Updated: 2024/09/14 16:51:16 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Brain
{
public:
	Brain();
	Brain(const Brain &obj);
	~Brain();
	Brain &operator=(const Brain &obj);

	// Optional functions for testing
	void printIdeas(int count) const;
	void setIdea(int index, const std::string &idea);

	std::string ideas[100];  // Array of 100 strings representing ideas
};
