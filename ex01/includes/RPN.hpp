/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:07:58 by root              #+#    #+#             */
/*   Updated: 2023/03/23 09:21:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <cctype>
# include <stdlib.h>

bool	is_operand(int c);
void	check_arg(int ac, char** av);
void	calculation(std::stack<int>& data, const char operand);