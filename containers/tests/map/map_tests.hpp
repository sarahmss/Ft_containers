/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 22:07:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_HPP
#define MAP_TESTS_HPP

#include "./../minunit.h"
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>

#if 1//CREATE A REAL STL EXAMPLE
	namespace ft = std;
#else
	#include "../../map.hpp"
#endif

#define IntMapType	ft::map<int, int>
#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#endif //MAP_TESTS_HPP
