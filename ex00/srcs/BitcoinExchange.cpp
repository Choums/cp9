/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:30 by root              #+#    #+#             */
/*   Updated: 2023/03/14 17:50:36 by root             ###   ########.fr       */
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
