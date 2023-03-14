/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:50:25 by root              #+#    #+#             */
/*   Updated: 2023/03/14 18:47:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*
 *	1-	Verif file's name
 *	2-	Open file
 *	3-	Check Content
 *	4-	Get stream line by line
 *	5-	
*/

void	check_arg(int ac, char **av)
{
	if (ac == 1)
		
	if (ac != 2)
	{
		throw std::string("Error: Invalid Argument.");
		return ;
	}
	std::string	file(av[1]);
}

void	check_data(void)
{
	
}

int	main(int ac, char **av)
{
	try {
		// if (ac == 1)
		// 	throw std::string("Error: Could not open file.");
		// if (ac > 2)
		// 	throw std::string("Error: Invalid Arguments.");
		(void)av;
		(void)ac;
		std::ifstream file;
		file.open("data.csv", std::ifstream::in);
		if (!file.is_open())
			throw std::string("Error: Cannot open csv file.");
		
		std::map<std::string, float> data;
		
		std::string str;
		std::getline(file, str);
		str.clear();
		for (std::string line; std::getline(file, line); )
		{
			// std::cout << line << std::endl;
			size_t	pos = 0;

			std::string	sub1 = line.substr(pos, line.find(','));
			pos = sub1.size() + 1;
			std::string	sub2 = line.substr(pos, line.find('\n'));
			
			char	*end_ptr;
			float	num = static_cast<float>(strtod(sub2.c_str(), &end_ptr));
		
			data.insert(std::pair<std::string, float>(sub1, num));
			line.clear();
		}

		for(std::map<std::string, float>::iterator it = data.begin(); it != data.end(); ++it)
		    std::cout << it->first << "," << it->second << "\n";
	}
	catch (std::string& e) {
		std::cout << e << std::endl;
		return (1);
	}
	return (0);
}