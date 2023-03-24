/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:31 by root              #+#    #+#             */
/*   Updated: 2023/03/24 11:59:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>
#include <sys/time.h>

bool	str_digit(const char* str);
void	check_arg(int ac, char** av, std::vector<int>& arr, std::list<int>& lst);
