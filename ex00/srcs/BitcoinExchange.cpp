/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:30 by root              #+#    #+#             */
/*   Updated: 2023/03/21 19:05:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void	check_arg(int ac, char **av, std::ifstream &file)
{
	if (ac == 1 || !av[1])
		throw std::string("Error: Could not open file.");
	if (ac > 2)
		throw std::string("Error: Invalid Arguments.");
	file.open("data.csv", std::ifstream::in);
	if (!file.is_open())
		throw std::string("Error: Cannot open csv file.");
}

bool	str_digit(const char* str)
{
	for (int i(0); str[i]; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

//	Position du premier tiret entre l'année et le mois
#define	FST_DASH 4
//	Position du second tiret entre le mois et le jour
#define	SND_DASH 7

bool	check_date(std::string date)
{
	if (date.size() != 10 || date[FST_DASH] != '-' || date[SND_DASH] != '-')
		return (false);

	size_t	pos(0);
	size_t	new_pos(0);
	while (pos != std::string::npos)
	{
		if (pos)
		{
			new_pos = pos + 1;
			// std::cout << "there " << std::endl;
		}
		else
			new_pos = pos;
		pos = date.find('-', new_pos);
		// std::cout << "pos: " << pos << std::endl << "new: " << new_pos << std::endl;
		std::string	str = date.substr(new_pos, pos);
		// std::cout << "str: " << str << std::endl;
		if (pos == FST_DASH && strlen(str.c_str()) != 4 && !str_digit(str.c_str()))
			return (false);
		else if (pos == SND_DASH)
		{
			int	num = atoi(str.c_str());
			// std::cout << "month: " << num << std::endl;
			if (!(num >= 1 && num <= 12))
				return (false);
		}
		else if (pos == std::string::npos)
		{
			int	num = atoi(str.c_str());
			// std::cout << "day: " << num << std::endl;
			if (!(num >= 1 && num <= 31))
				return (false);
		}
	}
	return (true);
}

void	readLine(std::ifstream&	file, std::multimap<std::string, double>& data, const char* sep)
{
	std::string str;
	std::getline(file, str);
	str.clear();
	for (std::string line; std::getline(file, line); )
	{
		// std::cout << line << std::endl;
		size_t	new_pos = 0;
		size_t	pos = line.find(sep);
		
		std::string	sub1 = line.substr(new_pos, pos);
		std::string	sub2;
		if (pos != std::string::npos)
		{	
			new_pos = pos + strlen(sep);
			pos = line.find('\n');
			sub2 = line.substr(new_pos, pos);
		}
	
		// char	*end_ptr;
		// float	num = static_cast<float>(strtod(sub2.c_str(), &end_ptr));
		double	num;
		if (sub2.empty())
			num = std::numeric_limits<double>::quiet_NaN();
		else
			num = atof(sub2.c_str());
		data.insert(std::pair<std::string, double>(sub1, num));
		line.clear();
	}
	// std::cout << std::endl << "---r---" << std::endl;
}

void	print_rate(std::multimap<std::string, double>& data, std::multimap<std::string, double>& rate)
{
	std::multimap<std::string, double>::iterator	it;
	for (std::multimap<std::string, double>::iterator mit = rate.begin(); mit != rate.end(); mit++)
	{
		it = data.find(mit->first);
		if (it == data.end())
			it = data.lower_bound(mit->first);
		if (!check_date(mit->first) || std::isnan(mit->second))
			std::cout << "Error: bad input => " << mit->first << std::endl;
		else if (mit->second < 0)
			std::cout << "Error: not a positive number" << std::endl;
		else if (mit->second > 1000/*static_cast<double>(std::numeric_limits<int>::max())*/)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << mit->first << " => " << mit->second << " = " << (it->second * mit->second) << std::endl;			 
	}
}