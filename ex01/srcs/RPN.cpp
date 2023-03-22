/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:08:07 by root              #+#    #+#             */
/*   Updated: 2023/03/22 17:35:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool	is_operand(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

/*
 *	1 arg
 *	chiffre de 0 à 9	
 *	Opérandes: "+ - * \"
 *	Autres caractères => throw Error 
*/
void	check_arg(int ac, char** av)
{
	if (ac != 2 || !av[1])
		throw std::exception();

	std::string str = av[1];
	int i(0);

	while (str[i])
	{
		// std::cout << "i(" << i << "): " << str[i] << std::endl;
		if (str[i] == ' ')
			i++;
		if ((!std::isdigit(str[i])	&&	av[1][i] != '+'
									&&	av[1][i] != '-'
									&&	av[1][i] != '*'
									&&	av[1][i] != '/'))
			// std::cout << "err " << str[i] << std::endl;
			throw std::exception();
		else if (std::isdigit(str[i]) && std::isdigit(str[i + 1]))
			// std::cout << "err " << str[i] << std::endl;
			throw std::exception();
		i++;
	}
}