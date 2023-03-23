/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:50 by root              #+#    #+#             */
/*   Updated: 2023/03/23 20:48:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int ac, char** av)
{
	try {
		std::vector<int>	arr;
		std::list<int>		lst;
		check_arg(ac, av, arr, lst);
		
		std::cout << "Before:\t";
		for (size_t	i(0); i != arr.size(); i++)
		{
			std::cout << arr[i];
			if (i == arr.size() - 1)
				std::cout << std::endl;
			else
				std::cout << ' ';
		}

		std::sort(arr.begin(), arr.end());
		lst.sort();
		
	}
	catch (std::exception&)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}