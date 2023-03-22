/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:07:58 by root              #+#    #+#             */
/*   Updated: 2023/03/22 17:40:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <cstdlib>

bool	is_operand(int c);
void	check_arg(int ac, char** av);
void	calculation(std::stack<int>& data, const char operand);