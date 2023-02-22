/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:59:31 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/22 12:16:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include "./minunit.h"
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <cstdio>

#if 0//CREATE A REAL STL EXAMPLE
	#include <map>
	#include <set>
	#include <vector>
	#include <stack>
	namespace ft = std;
#else
	#include "./../map.hpp"
	#include "./../set.hpp"
	#include "./../stack.hpp"
	#include "./../vector.hpp"
#endif

#define IntVectorType	ft::vector<int>
#define IntMapType		ft::map<int, int>
#define IntSetType		ft::set<int>
#define IntStackType	ft::stack<int>
#define IntPairType		ft::pair<int, int>
#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"
void	print_test(std::string test_name, bool test_result);

#endif //TESTS_HPP
