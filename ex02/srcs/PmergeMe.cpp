/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:49 by root              #+#    #+#             */
/*   Updated: 2023/03/23 10:16:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	str_digit(const char* str)
{
	for (int i(0); str[i]; i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}