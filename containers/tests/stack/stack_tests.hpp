/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 22:07:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTS_HPP
#define STACK_TESTS_HPP

#include "./../minunit.h"
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stack>

#if 0//CREATE A REAL STL EXAMPLE
	namespace ft = std;
#else
	#include "../../stack.hpp"
#endif

#define IntStackType	ft::stack<int>
#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"
void	print_test(std::string test_name, bool test_result);

#endif //STACK_TESTS_HPP
