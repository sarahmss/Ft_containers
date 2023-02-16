/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/16 14:48:30 by smodesto         ###   ########.fr       */
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

	IntMapType m1;
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);

	IntMapType m2(m1.begin(), m1.end());
	bool	test_result = m1 == m2;

	print_test("Instanciating range constructor: ", test_result);
	mu_assert(test_result == true, "error, map_range_constr");
}

void	test_map_copy_constructor( void )
{
	IntMapType m1;
	m1[1] = 2;
	m1[3] = 4;
	m1[5] = 6;

	IntMapType m2(m1);
	bool	test_result = m1 == m2;

	print_test("Instanciating copy constructor: ", test_result);
	mu_assert(test_result == true, "error, map_copy_constr");
}

void	test_map_assignment_operator( void )
{
	IntMapType m1;
	m1[1] = 2;
	m1[3] = 4;
	m1[5] = 6;

	IntMapType m2 = m1;
	bool	test_result = m1 == m2;

	print_test("operator=(): ", test_result);
	mu_assert(test_result == true, "error, operator=()");
}

void	test_map_get_allocator( void )
{
	ft::map<int, int>		m1;
	std::map<int, int>		m2;

	ft::map<int, int>::allocator_type alloc1 = m1.get_allocator();

	bool	test_result = typeid(alloc1) == typeid(std::allocator<ft::pair<int const, int> >);
	print_test("get_allocator(): ", test_result);
	mu_assert(test_result, "error, incorrect allocator type");
}

MU_TEST_SUITE(map_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING MAP MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_default_constr);
 	MU_RUN_TEST(test_map_range_constr);
	MU_RUN_TEST(test_map_copy_constructor);
	MU_RUN_TEST(test_map_assignment_operator);
	MU_RUN_TEST(test_map_get_allocator);
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
