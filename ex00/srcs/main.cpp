/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:50:25 by root              #+#    #+#             */
/*   Updated: 2023/03/15 18:28:12 by root             ###   ########.fr       */
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
		if (ac == 1 || !av[1])
			throw std::string("Error: Could not open file.");
		if (ac > 2)
			throw std::string("Error: Invalid Arguments.");
		std::ifstream file;
		file.open("data.csv", std::ifstream::in);
		if (!file.is_open())
			throw std::string("Error: Cannot open csv file.");
		
		std::map<std::string, double> data;
		
		std::string str;
		std::getline(file, str);
		str.clear();
		for (std::string line; std::getline(file, line); )
		{
			// std::cout << line << std::endl;
			size_t	new_pos = 0;
			size_t	pos = line.find(',');
			
			std::string	sub1 = line.substr(new_pos, pos);
			std::string	sub2;
			if (pos != std::string::npos)
			{	
				new_pos = pos + 1;
				pos = line.find('\n');
				sub2 = line.substr(new_pos, pos);
			}
		
			// char	*end_ptr;
			// float	num = static_cast<float>(strtod(sub2.c_str(), &end_ptr));
			double	num = atof(sub2.c_str());		
			data.insert(std::pair<std::string, double>(sub1, num));
			line.clear();
		}

		// for(std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it)
		//     std::cout << it->first << "," << it->second << "\n";
	
		/*	------ Input part ------- */
		std::ifstream	ifs;
		ifs.open(av[1], std::ifstream::in);
		if (!ifs.is_open())
			throw std::string("Error: Cannot open file.");
	
		std::multimap<std::string, double> rate;

		std::getline(ifs, str);
		str.clear();
		for (std::string line; std::getline(ifs, line); )
		{
			// std::cout << line << std::endl;
			size_t	new_pos = 0;
			size_t	pos = line.find(" | ");
			
			std::string	sub1 = line.substr(new_pos, pos);
			// std::cout << sub1 << std::endl;
			std::string	sub2;
			if (pos != std::string::npos)
			{	
				new_pos = pos + 3;
				pos = line.find('\n');
				sub2 = line.substr(new_pos, pos);
				// std::cout << sub2 << std::endl;
			}
			
			// char	*end_ptr;
			// float	num = static_cast<float>(strtod(sub2.c_str(), &end_ptr));
			double	num;
			if (sub2.empty())
				num = std::numeric_limits<double>::quiet_NaN();
			else
				num = atof(sub2.c_str());		
			rate.insert(std::pair<std::string, double>(sub1, num));
			line.clear();
		}
		std::cout << "-----" << std::endl;
		// for(std::multimap<std::string, double>::iterator it = rate.begin(); it != rate.end(); ++it)
		//     std::cout << it->first << " | " << it->second << "\n";
	
		/*	------ calcul du taux de change ------- */

		std::map<std::string, double>::iterator	it;
		for (std::multimap<std::string, double>::iterator mit = rate.begin(); mit != rate.end(); mit++)
		{
			it = data.find(mit->first);
			if (it == data.end())
				it = data.lower_bound(mit->first);
			if (isnan(mit->second))
				std::cout << "Error: bad input => " << mit->first << std::endl;
			else if (mit->second < 0)
				std::cout << "Error: not a positive number" << std::endl;
			else if (mit->second == static_cast<double>(std::numeric_limits<int>::max()))
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << mit->first << " => " << mit->second << " = " << (it->second * mit->second) << std::endl;			 
		}
	
	}
	catch (std::string& e) {
		std::cout << e << std::endl;
		return (1);
	}
	return (0);
}