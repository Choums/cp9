/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:50 by root              #+#    #+#             */
/*   Updated: 2023/03/23 10:19:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void	check_arg(int ac, char** av)
{
	if (ac < 2 || !av[1])
		throw std::exception();
	for (int i(1); i < ac; i++)
	{
		std::cout << "str: " << av[i] << std::endl;
		if (!str_digit(av[i]))
			throw std::exception();
	}
}

int	main(int ac, char** av)
{
	try {
		check_arg(ac, av);
	}
	catch (std::exception&)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}