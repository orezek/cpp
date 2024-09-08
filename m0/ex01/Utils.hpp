/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:35:36 by orezek            #+#    #+#             */
/*   Updated: 2024/09/08 13:23:23 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <limits>
# include <sstream>
# include <cstdlib>

namespace Utils {
	std::string	GetInput(const std::string& prompt);
	std::string	GetNumericInput(const std::string &prompt);
	bool		IsPhoneNumberValid(const std::string &phone);
	std::string	TrancStr(const std::string &str);
}
#endif
