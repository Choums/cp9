/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:08:39 by root              #+#    #+#             */
/*   Updated: 2023/03/24 15:41:26 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

void	calculation(std::stack<int>& data, const char operand)
{
	if (data.size() < 2)
		throw std::exception();
	// std::cout << "cal1" <<  std::endl;
	int	tmp = data.top();
	// std::cout << "tmp: " << tmp << std::endl;
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
		// std::cout << "=> " << str[i]  << " , " << isdigit(str[i]) << std::endl;
		if (std::isdigit(str[i]))
		{
			// std::cout << "adding" << std::endl;
			data.push(str[i] - '0');
		}
		if (is_operand(str[i]))
			calculation(data, str[i]);
		// std::cout << "data size: " << data.size() << std::endl;
	}

}

int	main(int ac, char** av)
{
	try {
		check_arg(ac, av);
		std::stack<int>	data;
		
		fill_stack(data, av[1]);

		if (data.size() != 1)
			throw std::exception();
		std::cout << data.top() << std::endl;
	}
	catch (std::exception&)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}