/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:49 by root              #+#    #+#             */
/*   Updated: 2023/03/23 20:49:02 by root             ###   ########.fr       */
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

void	check_arg(int ac, char** av, std::vector<int>& arr, std::list<int>& lst)
{
	if (ac < 2 || !av[1])
		throw std::exception();
	for (int i(1); i < ac; i++)
	{
		// std::cout << "str: " << av[i] << std::endl;
		if (!str_digit(av[i]))
			throw std::exception();
		arr.push_back(atoi(av[i]));
		lst.push_back(atoi(av[i]));
	}

	for (std::vector<int>::iterator	it = arr.begin(); it != arr.end(); it++)
		if (std::count(it, arr.end(), *it) > 1)
			throw std::exception();
}
