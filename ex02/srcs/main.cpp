/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:50 by root              #+#    #+#             */
/*   Updated: 2023/03/24 12:48:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
// 	+ tvalAfter.tv_usec) - tvalBefore.tv_usec

void	display_vector_sort(std::vector<int>& arr)
{
	struct timeval	start, end;
	unsigned long	time;

	std::cout << "After:\t";
	
	gettimeofday(&start, NULL);
	std::sort(arr.begin(), arr.end());
	gettimeofday(&end, NULL);

	for (size_t	i(0); i != arr.size(); i++)
	{
		std::cout << arr[i];
		if (i == arr.size() - 1)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
	time = ((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec) - start.tv_usec;
	std::cout << "Time to process a range of " << arr.size() << " with std::vector\t: " << time << std::endl;
}

void	display_list_sort(std::list<int>& lst)
{
	struct timeval	start, end;
	unsigned long	time;

	gettimeofday(&start, NULL);
	lst.sort();
	gettimeofday(&end, NULL);

	time = ((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec) - start.tv_usec;
	std::cout << "Time to process a range of " << lst.size() << " with std::list \t: " << time << std::endl;
}

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
		display_vector_sort(arr);
		display_list_sort(lst);
	}
	catch (std::exception&)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}