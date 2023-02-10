/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/10 14:27:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests/minunit.h"
#include <iostream>
#include <iomanip>

#if  0//CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "./vector.hpp"
#endif

#define KO "\033[1;31mKO\033[0m"
#define OK "\033[1;32mOK\033[0m"

/************************************ Vector Tests ************************************************/

void	print_test(std::string test_name, bool test_result)
{
	std::cout	<< std::setw(test_name.size() + 9) << ("| " + test_name)
				<< (test_result == true ? OK : KO) << std::setw(60 - (test_name.size() + 9))
				<< " | " << std::endl;
}

void vector_default_constr( void )
{
	ft::vector<int>	v;
	bool			test_result = v.empty();

	print_test("Instanciating default constructor: ", test_result);
	mu_assert(test_result == true, "error, vector_default_constr");
}

void vector_size_constr( void )
{
	ft::vector<int>	v(5);
	int				size = v.size();
	bool			test_result = true;
	bool			test_result1 = (size == 5);


	for (int i = 0; i < 5 && test_result == true; i++)
		test_result = (v[i] == 0 ? true : false);
	if (test_result == false || test_result1 == false)
		print_test("Instanciating size(5) value(10) constructor: ", false);
	else
		print_test("Instanciating size(5) value(10) constructor: ", true);
	mu_assert(test_result1, "error, wrong size");
	mu_assert(test_result, "error, wrong contet");
}
/*
void test_vector_size_value_constr( void )
{
	ft::vector<int> v(5, 10);
	int				size = v.size();
	bool			test_result = true;
	bool			test_result1 = (size == 5);

	for (int i = 0; i < 5 && test_result == true; i++)
		test_result = (v[i] == 10 ? true : false);
	if (test_result == false || test_result1 == false)
		print_test("Instanciating size(5) value(10) constructor: ", false);
	else
		print_test("Instanciating size(5) value(10) constructor: ", true);
	mu_assert(test_result1, "error, wrong size");
	mu_assert(test_result, "error, wrong contet");
}*/

MU_TEST_SUITE(vector_constructor_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING VECTOR CONSTRUCTOR TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(vector_default_constr);
	MU_RUN_TEST(vector_size_constr);
//	MU_RUN_TEST(test_vector_size_value_constr);
}

int main(void) {
	MU_RUN_SUITE(vector_constructor_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
