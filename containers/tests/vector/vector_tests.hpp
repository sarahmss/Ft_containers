/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 22:07:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include "./../minunit.h"
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>

#if 0//CREATE A REAL STL EXAMPLE
	namespace ft = std;
#else
	#include "../../vector.hpp"
#endif

#define IntVectorType	ft::vector<int>
#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

#endif //VECTOR_TESTS_HPP