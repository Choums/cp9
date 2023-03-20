/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:28 by root              #+#    #+#             */
/*   Updated: 2023/03/16 19:26:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <utility>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <cmath>

void	check_arg(int ac, char **av, std::ifstream &file);
void	readLine(std::ifstream&	file, std::multimap<std::string, double>& data, const char* sep);
void	print_rate(std::multimap<std::string, double>& data, std::multimap<std::string, double>& rate);