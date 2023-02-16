/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/16 14:08:49 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map_tests.hpp"
/*------------------------------- Member function ------------------------------------------------*/
void	print_test(std::string test_name, bool test_result);

void	test_map_default_constr( void )
{
	IntMapType		m1;
	bool			test_result = m1.empty();

	print_test("Instanciating default constructor: ", test_result);
	mu_assert(test_result == true, "error, map_default_constr");
}

void	test_map_range_constr( void )
{
	ft::pair<int, int> p1(1, 2);
	ft::pair<int, int> p2(3, 4);
	ft::pair<int, int> p3(5, 6);

	ft::map<int, int> m1;
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);

	ft::map<int, int> m2(m1.begin(), m1.end());
	bool	test_result = m1 == m2;

	print_test("Instanciating range constructor: ", test_result);
	mu_assert(test_result == true, "error, map_range_constr");
}

/*
void	test_map_size_value_constr( void )
{
	IntMapType m(5, 10);
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
}

void	test_assignment_operator( void )
{
	IntMapType	m1(5, 10);
	IntMapType	m2(5, 7);
	m1 = m2;
	bool			test_result = (m1 == m2);
	print_test("assinegment operator (both existing): ", test_result);
	mu_assert(test_result, "error, invalid assignment");
}

void	test_copy_constructor( void )
{
	IntMapType m1(5, 10);
	IntMapType m2 = m1;
	bool test_result = (m1 == m2);
	print_test("copy constructor: ", test_result);
	mu_assert(test_result, "error, unable to copy instance");
}

void	test_get_allocator( void )
{
	IntMapType m1(10, 10);
	IntMapType::allocator_type alloc = m1.get_allocator();
	bool			test_result = typeid(alloc) == typeid(std::allocator<int>);

	print_test("get_allocator(): ", test_result);
	mu_assert(test_result, "error, incorrect allocator type");
} */

MU_TEST_SUITE(map_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING MAP MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_default_constr);
 	MU_RUN_TEST(test_map_range_constr);
/*	MU_RUN_TEST(test_map_size_value_constr);
	MU_RUN_TEST(test_copy_constructor);
	MU_RUN_TEST(test_assignment_operator);
	MU_RUN_TEST(test_get_allocator); */
}

int	map_tests( void )
{
 	MU_RUN_SUITE(map_member_functions_tests);
/*	MU_RUN_SUITE(map_element_access_tests);
	MU_RUN_SUITE(map_iterators_tests);
	MU_RUN_SUITE(map_capacity_tests);
	MU_RUN_SUITE(map_modifiers_tests);
	MU_RUN_SUITE(map_no_member_functions);*/

	MU_REPORT();
	return MU_EXIT_CODE;
}
