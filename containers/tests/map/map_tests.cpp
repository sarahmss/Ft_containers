/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/17 15:55:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map_tests.hpp"
/*------------------------------- Member function ------------------------------------------------*/
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
	IntMapType		m1;

	IntMapType::allocator_type alloc1 = m1.get_allocator();

	bool	test_result = typeid(alloc1) == typeid(std::allocator<ft::pair<int const, int> >);
	print_test("get_allocator(): ", test_result);
	mu_assert(test_result, "error, incorrect allocator type");
}

MU_TEST_SUITE(map_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING MAP MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_default_constr);
 	MU_RUN_TEST(test_map_range_constr);
	MU_RUN_TEST(test_map_copy_constructor);
	MU_RUN_TEST(test_map_assignment_operator);
	MU_RUN_TEST(test_map_get_allocator);
}

/*------------------------------- Element access ------------------------------------------------*/

void	test_map_access_operator_valid_index( void )
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	m1[5] = 424242;
	bool			test_result = true;

	if ((m1[1] != 42) || (m1[3] != 4242) || (m1[5] != 424242))
		test_result = false;
	print_test("operator[] valid index: ", test_result);
	mu_assert(test_result, "error, accessing valid index");
}

void	test_map_access_operator_invalid_index( void )
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	m1[5] = 424242;

	try
	{
		m1[7];
		print_test("operator[] invalid index: ", true);
		mu_assert(true, "error:out_of_range_exception not thrown");
	}
	catch (const std::out_of_range &exception)
	{
		print_test("operator[] invalid index: ", false);
		mu_assert(false, "error: out_of_range_exception thrown");
	}
}

MU_TEST_SUITE(map_element_access_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING MAP ELEMENT ACCESS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_access_operator_valid_index);
	MU_RUN_TEST(test_map_access_operator_invalid_index);
}

/*------------------------------- Iterators ------------------------------------------------*/

void	test_map_begin_iterator( void ) // increment from begin to end
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	IntMapType::iterator begin = m1.begin();
	bool	test_result = true;

	if ((begin->first != 1) || (begin++->second != 42)
		|| (begin->first != 3) || (begin->second != 4242))
		test_result = false;
	print_test("begin(): ", test_result);
	mu_assert(test_result, "error, wrong begin iterator");
}

void	test_map_rbegin_iterator( void ) //increment from end to begin0.00054603
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	IntMapType::reverse_iterator rbegin = m1.rbegin();
	bool	test_result = true;

	if ((rbegin->first != 3) || (rbegin++->second != 4242)
		|| (rbegin->first != 1) || (rbegin->second != 42))
		test_result = false;
	print_test("rbegin(): ", test_result);
	mu_assert(test_result, "error, wrong rbegin iterator");
}

void	test_map_end_iterator( void ) // decrement from end to begin
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	IntMapType::iterator end = m1.end();
	bool	test_result = true;

	if (((--end)->first != 3) || (end->second != 4242)
		|| ((--end)->first != 1) || (end->second != 42))
		test_result = false;
	print_test("end(): ", test_result);
	mu_assert(test_result, "error, wrong end iterator");
}

void	test_map_rend_iterator( void ) // decrement from begin to end
{
	IntMapType m1;
	m1[1] = 42;
	m1[3] = 4242;
	IntMapType::reverse_iterator rend = m1.rend();
	bool	test_result = true;

	if (((--rend)->first != 1) || (rend->second != 42)
		|| ((--rend)->first != 3) || (rend->second != 4242))
		test_result = false;
	print_test("rend(): ", test_result);
	mu_assert(test_result, "error, wrong rend iterator");
}

MU_TEST_SUITE(map_iterators_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING MAP ITERATORS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_begin_iterator);
	MU_RUN_TEST(test_map_rbegin_iterator);
	MU_RUN_TEST(test_map_end_iterator);
	MU_RUN_TEST(test_map_rend_iterator);
}

/*------------------------------------- Modifiers ------------------------------------------------*/

void	test_map_swap_method( void )
{
	IntMapType m1;
	IntMapType m2;
	bool test_result = false;

	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;
	m2[4] = 4;
	m2[5] = 5;
	m2[6] = 6;
	m1.swap(m2);

	if (m1.size() == 3 && m1[4] == 4 && m1[5] == 5 && m1[6] == 6
		&& m2.size() == 3 && m2[1] == 1 && m2[2] == 2 && m2[3] == 3)
		test_result = true;
	print_test("swap() [method]: ", test_result);
	mu_assert(test_result, "error, Something failed in Swapping");
}

void	test_map_clear( void )
{
	IntMapType	m1;
	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;
	m1.clear();
	bool			test_result = m1.empty();

	print_test("clear(): ", test_result);
	mu_assert(test_result == true, "error, clear() method");
}

void	test_map_insert_value( void )
{
	ft::pair<int, int>	p1(42, 42);
	IntMapType			m1;
	m1.insert(p1);
	bool	test_result = true;

	if (m1[42] != 42)
		test_result = false;
	print_test("insert(value): ", test_result);
	mu_assert(test_result == true, "error, insert(value) method");
}

void	test_map_insert_pos_value( void )
{
	IntMapType				m1;
	ft::pair<int, int>		p1(42, 42);
	bool					test_result = true;

	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;
	m1.insert(m1.end(), p1);
	if (m1[42] != 42)
		test_result = false;
	print_test("insert(pos, value): ", test_result);
	mu_assert(test_result == true, "error, insert(pos, value) method");
}

void	test_map_insert_first_last( void )
{
	IntMapType	m2;
	IntMapType	m1;
	bool		test_result;

	ft::pair<int, int> p1(1, 2);
	ft::pair<int, int> p2(3, 4);
	ft::pair<int, int> p3(5, 6);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);

	m2.insert(m1.begin(), m1.end());
	test_result = m1 == m2;

	print_test("insert(first, last): ", test_result);
	mu_assert(test_result == true, "error, insert(first, last) method");
}

void	test_map_erase_key( void )
{
	IntMapType				m1;
	bool					test_result = true;

	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;
	m1.erase(1);
	if (m1.size() != 2 || m1[2] != 2 || m1[3] != 3)
		test_result = false;
	print_test("erase(key): ", test_result);
	mu_assert(test_result, "error, erase(key) method");
}

void	test_map_erase_pos( void )
{
	IntMapType				m1;
	bool					test_result = true;

	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;
	m1.erase(m1.begin());
	if (m1.size() != 2 || m1[2] != 2 || m1[3] != 3)
		test_result = false;
	print_test("erase(pos): ", test_result);
	mu_assert(test_result, "error, erase(pos) method");
}

void	test_map_erase_first_last( void )
{
	IntMapType	m1;

	ft::pair<int, int> p1(1, 2);
	ft::pair<int, int> p2(3, 4);
	ft::pair<int, int> p3(5, 6);

	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.erase(m1.begin(), m1.end());
	bool		test_result = m1.empty();

	print_test("erase(first, last): ", test_result);
	mu_assert(test_result == true, "error, erase(first, last) method");
}

MU_TEST_SUITE(map_modifiers_tests)
{
		std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING MAP MODIFIERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_clear);
	MU_RUN_TEST(test_map_insert_value);
	MU_RUN_TEST(test_map_insert_pos_value);
	MU_RUN_TEST(test_map_insert_first_last);
	MU_RUN_TEST(test_map_erase_key);
	MU_RUN_TEST(test_map_erase_pos);
	MU_RUN_TEST(test_map_erase_first_last);
	MU_RUN_TEST(test_map_swap_method);
}

/*------------------------------------- Capacity ------------------------------------------------*/

void	test_map_max_size( void )
{
	IntMapType			m1;
	bool			test_result = m1.max_size();

	print_test("max_size(): ", test_result);
	mu_assert(test_result, "error, wrong max_size()");
}

void	test_map_size( void )
{
	IntMapType	m1;
	m1[1] = 10;
	m1[2] = 20;
	m1[3] = 30;
	m1[4] = 40;
	m1[5] = 50;
	bool			test_result = m1.size() == 5;

	print_test("size(): ", test_result);
	mu_assert(test_result == true, "error, wrong size()");
}

void	test_map_empty( void )
{
	IntMapType	m1;
	bool			test_result = m1.empty();

	print_test("empty() [empty map]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

void	test_map_not_empty( void )
{
	IntMapType	m1;
	m1[1] = 42;
	bool			test_result = m1.empty() == false;

	print_test("empty() [not empty map]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

MU_TEST_SUITE(map_capacity_tests)
{
		std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING MAP CAPACITY TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_map_empty);
	MU_RUN_TEST(test_map_not_empty);
	MU_RUN_TEST(test_map_size);
	MU_RUN_TEST(test_map_max_size);
}

int	map_tests( void )
{
 	MU_RUN_SUITE(map_member_functions_tests);
	MU_RUN_SUITE(map_element_access_tests);
	MU_RUN_SUITE(map_iterators_tests);
	MU_RUN_SUITE(map_capacity_tests);
	MU_RUN_SUITE(map_modifiers_tests);
/*	MU_RUN_SUITE(map_no_member_functions);*/

	MU_REPORT();
	return MU_EXIT_CODE;
}
