/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:08:39 by root              #+#    #+#             */
/*   Updated: 2023/03/22 18:07:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

enum operand {
	add = '+',
	sus = '-',
	mul = '*',
	dyv = '/'};

void	calculation(std::stack<int>& data, const char operand)
{
	if (data.size() < 2)
		throw std::exception();
	int	tmp = data.top();
	data.pop();
	switch (operand)
	{
		case add:
			data.top() += tmp;	break;
		case sus:
			data.top() -= tmp;	break;
		case mul:
			data.top() *= tmp;	break;
		case dyv:
			data.top() /= tmp;	break;
	}
	
}

int	main(int ac, char** av)
{
	try {
		check_arg(ac, av);
		std::stack<int>	data;
		std::string str = av[1];
		for (size_t i(0); str; str++)
		{
			std::cout << "=> " << str[i] << std::endl;
			if (std::isdigit(str[i]))
			{
				std::cout << "adding" << std::endl;
				data.push(2);
			}
			if (is_operand(str[i]))
				calculation(data, str[i]);
			if (str[i] == ' ')
			{
				std::cout << "space" << std::endl;
				i++;
			}
			// std::cout << data.size() << std::endl;
		}
	}
	catch (std::exception&)
	{
		std::cerr << "Error\n" << std::endl;
		return (1);
	}
	return (0);
}