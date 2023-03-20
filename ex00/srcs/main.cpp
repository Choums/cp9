/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:50:25 by root              #+#    #+#             */
/*   Updated: 2023/03/16 19:28:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void	check_data(void)
{
	
}

int	main(int ac, char **av)
{
	try {
		std::ifstream file;
		std::multimap<std::string, double> data;
		check_arg(ac, av, file);
		readLine(file, data, ",");

		// for(std::multimap<std::string, double>::iterator it = data.begin(); it != data.end(); ++it)
		//     std::cout << it->first << "," << it->second << "\n";
	
		/*	------ Input part ------- */
		std::ifstream	ifs;
		ifs.open(av[1], std::ifstream::in);
		if (!ifs.is_open())
			throw std::string("Error: Cannot open file.");
	
		std::multimap<std::string, double> rate;
		readLine(ifs, rate, " | ");
		
		// std::cout << "-----" << std::endl << std::endl;
		// for(std::multimap<std::string, double>::iterator it = rate.begin(); it != rate.end(); ++it)
		//     std::cout << it->first << " | " << it->second << "\n";
	
		/*	------ calcul du taux de change ------- */

		print_rate(data, rate);
	}
	catch (std::string& e) {
		std::cout << e << std::endl;
		return (1);
	}
	return (0);
}