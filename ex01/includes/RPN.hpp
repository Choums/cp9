/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:07:58 by root              #+#    #+#             */
/*   Updated: 2023/03/24 15:29:35 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <cctype>
# include <stdlib.h>

enum operand {
	add = '+',
	sus = '-',
	mul = '*',
	dyv = '/'};

bool	is_operand(int c);
void	check_arg(int ac, char** av);
void	calculation(std::stack<int>& data, const char operand);