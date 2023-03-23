/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:08:39 by root              #+#    #+#             */
/*   Updated: 2023/03/23 09:30:50 by root             ###   ########.fr       */
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
	std::cout << "cal1" <<  std::endl;
	int	tmp = data.top();
	std::cout << "tmp: " << tmp << std::endl;
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

void	fill_stack(std::stack<int>& data, char* str)
{
	for (size_t i(0); str[i]; i++)
	{
		std::cout << "=> " << str[i]  << " , " << std::isdigit(str[i]) << std::endl;
		if (std::isdigit(str[i]))
		{
			std::cout << "adding" << std::endl;
			data.push(str[i] - '0');
		}
		if (is_operand(str[i]))
			calculation(data, str[i]);
		if (str[i] == ' ')
		{
			std::cout << "space" << std::endl;
			i++;
		}
		// std::cout << "data size: " << data.size() << std::endl;
	}

}

int	main(int ac, char** av)
{
	try {
		check_arg(ac, av);
		std::stack<int>	data;
		
		fill_stack(data, av[1]);

		std::cout << data.top() << std::endl;
	}
	catch (std::exception&)
	{
		std::cerr << "Error\n" << std::endl;
		return (1);
	}
	return (0);
}