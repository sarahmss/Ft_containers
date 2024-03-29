/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/22 13:32:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.hpp"

/*------------------------------- Member function ------------------------------------------------*/
void	print_test(std::string test_name, bool test_result)
{
	std::cout	<< std::setw(test_name.size() + 9) << ("| " + test_name)
				<< (test_result == true ? OK : KO) << std::setw(60 - (test_name.size() + 9))
				<< " | " << std::endl;
}

void	test_vector_default_constr( void )
{
	IntVectorType	v;
	bool			test_result = v.empty();

	print_test("Instanciating default constructor: ", test_result);
	mu_assert(test_result == true, "error, vector_default_constr");
}

void	test_vector_size_constr( void )
{
	IntVectorType	v(5);
	int				size = v.size();
	bool			test_result = true;
	bool			test_result1 = (size == 5);


	for (int i = 0; i < 5 && test_result == true; i++)
		test_result = (v[i] == 0 ? true : false);
	if (test_result == false || test_result1 == false)
		print_test("Instanciating size(5) constructor: ", false);
	else
		print_test("Instanciating size(5) constructor: ", true);
	mu_assert(test_result1, "error, wrong size");
	mu_assert(test_result, "error, wrong contet");
}

void	test_vector_size_value_constr( void )
{
	IntVectorType v(5, 10);
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
	IntVectorType	v1(5, 10);
	IntVectorType	v2(5, 7);
	v1 = v2;
	bool			test_result = (v1 == v2);
	print_test("assinegment operator (both existing): ", test_result);
	mu_assert(test_result, "error, invalid assignment");
}

void	test_copy_constructor( void )
{
	IntVectorType v1(5, 10);
	IntVectorType v2 = v1;
	bool test_result = (v1 == v2);
	print_test("copy constructor: ", test_result);
	mu_assert(test_result, "error, unable to copy instance");
}

void	test_get_allocator( void )
{
	IntVectorType v(10, 10);
	IntVectorType::allocator_type alloc = v.get_allocator();
	bool			test_result = typeid(alloc) == typeid(std::allocator<int>);

	print_test("get_allocator(): ", test_result);
	mu_assert(test_result, "error, incorrect allocator type");
}

MU_TEST_SUITE(vector_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_vector_default_constr);
	MU_RUN_TEST(test_vector_size_constr);
	MU_RUN_TEST(test_vector_size_value_constr);
	MU_RUN_TEST(test_copy_constructor);
	MU_RUN_TEST(test_assignment_operator);
	MU_RUN_TEST(test_get_allocator);
}

/*------------------------------- Element access ------------------------------------------------*/

void	test_at_method_valid_index( void )
{
	IntVectorType	v(5, 42);
	bool			test_result = true;

	int len = v.size();
	for (int i = 0; i < len; i++)
		if (v.at(i) != 42)
			test_result = false;
	print_test("at() valid index: ", test_result);
	mu_assert(test_result, "error, accessing valid index");
}

void	test_at_method_invalid_index( void )
{
	IntVectorType	v(5, 42);

	try
	{
		v.at(7);
		print_test("at() invalid index: ", false);
		mu_assert(false, "error:out_of_range_exception not thrown");
	}
	catch (const std::out_of_range &exception)
	{
		print_test("at() invalid index: ", true);
		mu_assert(true, "error: out_of_range_exception not thrown");
	}
}

void	test_access_operator_valid_index( void )
{
	IntVectorType	v(5, 42);
	bool			test_result = true;

	int len = v.size();
	for (int i = 0; i < len; i++)
		if (v[i] != 42)
			test_result = false;
	print_test("operator[] valid index: ", test_result);
	mu_assert(test_result, "error, accessing valid index");
}

void	test_access_operator_invalid_index( void )
{
	IntVectorType	v(5, 42);

	try
	{
		v[7];
		print_test("operator[] invalid index: ", true);
		mu_assert(true, "error:out_of_range_exception not thrown");
	}
	catch (const std::out_of_range &exception)
	{
		print_test("operator[] invalid index: ", false);
		mu_assert(false, "error: out_of_range_exception thrown");
	}
}

void	test_front_method( void )
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	int front = v1.front();
	bool	test_result = front == 42;

	print_test("front(): ", test_result);
	mu_assert(test_result, "error, wrong front element");
}

void	test_back_method( void )
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	int back = v1.back();
	bool	test_result = back == 424242;

	print_test("back(): ", test_result);
	mu_assert(test_result, "error, wrong back element");
}

void	test_data_method( void )
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	int	*data = v1.data();
	bool	test_result = true;

	if ((*data != 42) || (*(data + 1) != 4242) || (*(data + 2) != 424242))
		test_result = false;
	print_test("data(): ", test_result);
	mu_assert(test_result, "error, wrong back element");
}

MU_TEST_SUITE(vector_element_access_tests)
{
	std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR ELEMENT ACCESS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_at_method_valid_index);
	MU_RUN_TEST(test_at_method_invalid_index);
	MU_RUN_TEST(test_access_operator_valid_index);
	MU_RUN_TEST(test_access_operator_invalid_index);
	MU_RUN_TEST(test_front_method);
	MU_RUN_TEST(test_back_method);
	MU_RUN_TEST(test_data_method);
}

/*------------------------------- Iterators ------------------------------------------------*/

void	test_begin_iterator( void ) // increment from begin to end
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	IntVectorType::iterator begin = v1.begin();
	bool	test_result = true;

	if ((*begin++ != 42) || (*begin++ != 4242) || (*begin != 424242))
		test_result = false;
	print_test("begin(): ", test_result);
	mu_assert(test_result, "error, wrong begin iterator");
}

void	test_rbegin_iterator( void ) //increment from end to begin0.00054603
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	IntVectorType::reverse_iterator rbegin = v1.rbegin();
	bool	test_result = true;

	if ((*rbegin++ != 424242) || (*rbegin++ != 4242) || (*rbegin != 42))
		test_result = false;
	print_test("rbegin(): ", test_result);
	mu_assert(test_result, "error, wrong rbegin iterator");
}

void	test_end_iterator( void ) // decrement from end to begin
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	IntVectorType::iterator end = v1.end();
	bool	test_result = true;

	if ((*(--end) != 424242) || (*(--end) != 4242) || (*(--end) != 42))
		test_result = false;
	print_test("end(): ", test_result);
	mu_assert(test_result, "error, wrong end iterator");
}

void	test_rend_iterator( void ) // decrement form begin to endend
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	IntVectorType::reverse_iterator rend = v1.rend();
	bool	test_result = true;

	if ((*(--rend) != 42) || (*(--rend) != 4242) || (*(--rend) != 424242))
		test_result = false;
	print_test("rend(): ", test_result);
	mu_assert(test_result, "error, wrong rend iterator");
}

void	test_compare_iterator( void ) // decrement form begin to endend
{
	IntVectorType	v1;
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	IntVectorType::iterator begin = v1.begin();
	IntVectorType::const_iterator const_begin = v1.begin();

	bool	test_result = begin == const_begin;;

	print_test("Comparing const_iterator and iterator: ", test_result);
	mu_assert(test_result, "error, wrong rend iterator");
}

MU_TEST_SUITE(vector_iterators_tests)
{
	std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR ITERATORS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_begin_iterator);
	MU_RUN_TEST(test_end_iterator);
	MU_RUN_TEST(test_rend_iterator);
	MU_RUN_TEST(test_rbegin_iterator);
	MU_RUN_TEST(test_compare_iterator);
}

/*------------------------------------- Capacity ------------------------------------------------*/

void	test_capacity( void )
{
	IntVectorType	v1(5, 10);

	bool	test_result = v1.capacity() == v1.size();

	print_test("capacity(): ", test_result);
	mu_assert(test_result, "error, capacity() failed");
}

void	test_capacity_reserved_memory( void )
{
	IntVectorType	v1;
	v1.reserve(100);
	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	bool	test_result = v1.capacity() > v1.size();

	print_test("capacity() of reserved memory: ", test_result);
	mu_assert(test_result, "error, capacity() of reserved memory failed");
}

void	test_reserve( void )
{
	IntVectorType v1;
	v1.reserve(100);
	bool test_result = v1.capacity() == 100;

	print_test("reserve(): ", test_result);
	mu_assert(test_result, "error, reserve failed");
}

void	test_max_size( void )
{
	IntVectorType		v;
	bool				test_result = v.max_size();

	print_test("max_size(): ", test_result);
	mu_assert(test_result, "error, wrong max_size()");
}

void	test_size( void )
{
	IntVectorType	v(15, 15);
	bool			test_result = v.size() == 15;

	print_test("size(): ", test_result);
	mu_assert(test_result == true, "error, wrong size()");
}

void	test_empty( void )
{
	IntVectorType	v;
	bool			test_result = v.empty();

	print_test("empty() [empty vector]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

void	test_not_empty( void )
{
	IntVectorType	v(5, 10);
	bool			test_result = v.empty() == false;

	print_test("empty() [not empty vector]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

void	test_deep_copy( void )
{
	IntVectorType	v1;
	IntVectorType	v2;
	bool			test_result = true;

	for (int i = 0; i < 1000; i++)
		v1.push_back(i);
	v2 = v1;
	IntVectorType::iterator it1 = v1.begin();
	IntVectorType::iterator it2 = v2.begin();
	for (int i = 0; i < 1000; i++)
	{
		if (it1 == it2 || *it1 != *it2)
			test_result = false;
		it1++;
		it2++;
	}
	v2[5] = 10;
	if (v1[5] == v2[5])
		test_result = false;
	print_test("Vector performance: ", test_result);
	mu_assert(test_result, "error, deep copy failed");
}

MU_TEST_SUITE(vector_capacity_tests)
{
		std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR CAPACITY TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_empty);
	MU_RUN_TEST(test_not_empty);
	MU_RUN_TEST(test_size);
	MU_RUN_TEST(test_max_size);
	MU_RUN_TEST(test_reserve);
	MU_RUN_TEST(test_capacity);
	MU_RUN_TEST(test_capacity_reserved_memory);
	MU_RUN_TEST(test_deep_copy);

}

/*------------------------------------- Modifiers ------------------------------------------------*/

void test_swap_method( void )
{
	IntVectorType v1;
	IntVectorType v2;
	bool test_result = false;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v1.swap(v2);

	if (v1.size() == 3 && v1[0] == 4 && v1[1] == 5 && v1[2] == 6
		&& v2.size() == 3 && v2[0] == 1 && v2[1] == 2 && v2[2] == 3)
		test_result = true;
	/*
						Checking Iterators
	for (IntVectorType::iterator i1 = v1.begin(); i1 != v1.end(); i1++)
		std::cout << *i1 << ' ';
	for (IntVectorType::iterator i2 = v2.begin(); i2 != v2.end(); i2++)
		std::cout << *i2 << ' ';
	*/
	print_test("swap() [method]: ", test_result);
	mu_assert(test_result, "error, Something failed in Swapping");
}

void	test_resize_greater( void )
{
	IntVectorType	v1;
	bool			test_result = true;

	v1.push_back(42);
	v1.push_back(4242);

	v1.resize(4, 24);
	if (v1.size() != 4 || v1[0] != 42 || v1[1] != 4242 || v1[2] != 24 || v1[3] != 24)
		test_result = false;
	print_test("resize() greater[2 -> 4]: ", test_result);
	mu_assert(test_result, "error, resize() failed to expand the vector size or insert elements");
}

void	test_resize_smaller( void )
{
	IntVectorType	v1;
	bool			test_result = true;

	v1.push_back(42);
	v1.push_back(4242);
	v1.push_back(424242);
	v1.push_back(42424242);

	v1.resize(3);
	if (v1.size() != 3 || v1[0] != 42 || v1[1] != 4242 || v1[2] != 424242)
		test_result = false;
	print_test("resize() smaller[4 -> 3]: ", test_result);
	mu_assert(test_result, "error, resize() failed to shrink the vector size or preserv elements");
}

void	test_pop_back( void )
{
	IntVectorType	v1(5, 42);
	bool			test_result = true;


	v1[3] = 24;
	v1.pop_back();
	if (*v1.rbegin() != 24)
		test_result = false;
	print_test("pop_back(): ", test_result);
	mu_assert(test_result, "error, pop_back() method");
}

void	test_push_back( void )
{
	IntVectorType	v1(5, 42);
	bool			test_result = true;

	v1.push_back(24);
	if (*v1.rbegin() != 24)
		test_result = false;
	print_test("push_back(): ", test_result);
	mu_assert(test_result, "error, push_back() method");
}

void	test_erase_pos( void )
{
	IntVectorType				v1(10, 42);
	v1[5] = 24;
	IntVectorType::iterator		it = v1.begin();
	bool			test_result = true;

	for (; it != v1.end(); it++)
		if (*it == 24)
			v1.erase(it);
	if (v1.size() != 9)
		test_result = false;
	print_test("erase(pos): ", test_result);
	mu_assert(test_result, "error, erase(pos) method");
}

void	test_erase_first_last( void )
{
	IntVectorType				v1(10, 42);
	bool						test_result = true;
	IntVectorType::iterator it = v1.begin();

	v1[5] = 24;
	while (*it != 24)
		it++;
	v1.erase(v1.begin(), it);
	if (v1.size() != 5)
		test_result = false;
	print_test("erase(first, last): ", test_result);
	mu_assert(test_result, "error, erase(first, last) method");
}

void	test_insert_pos_value( void )
{
	IntVectorType	v;
	bool			test_result = true;

	for (int i = 0; i < 10; i++)
		v.insert(v.end(), 42 + i);
	for (int i = 0; i < 10; i++)
		if (v[i] != 42 + i)
			test_result = false;
	print_test("insert(pos, value): ", test_result);
	mu_assert(test_result == true, "error, insert(pos, value) method");
}

void	test_insert_pos_count_value( void )
{
	IntVectorType	v;
	bool			test_result = true;

	for (int i = 0; i < 10; i++)
		v.insert(v.begin(), 42, 42);
	for (int i = 0; i < 42; i++)
		if (v[i] != 42)
			test_result = false;
	print_test("insert(pos, count, value): ", test_result);
	mu_assert(test_result == true, "error, insert(pos, count, value) method");
}

/*
	-> Enable_if condition is added as a fourth template parameter to the insert method,
		checking if InputIt is not an integral type.
	-> If InputIt is an integral type, the enable_if condition evaluates to false,
		causing a compiler error. If InputIt is not an integral type,
		the enable_if condition evaluates to true, allowing the method to execute normally.
*/
void	test_insert_pos_first_last( void )
{
	IntVectorType	v;
	IntVectorType	v2;
	bool			test_result = true;

	for (int i = 0; i < 10; i++)
		v.insert(v.end(), 42 + i);
	v2.insert(v2.begin(), v.begin(), v.end());
	print_test("insert(pos, first, last): ", test_result);
	mu_assert(test_result == true, "error, insert iterators method");
}

void	test_clear( void )
{
	IntVectorType	v(5, 10);
	v.clear();
	bool			test_result = v.empty();

	print_test("clear(): ", test_result);
	mu_assert(test_result == true, "error, clear() method");
}

MU_TEST_SUITE(vector_modifiers_tests)
{
		std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR MODIFIERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_clear);
	MU_RUN_TEST(test_insert_pos_value);
	MU_RUN_TEST(test_insert_pos_count_value);
	MU_RUN_TEST(test_insert_pos_first_last);
	MU_RUN_TEST(test_erase_pos);
	MU_RUN_TEST(test_erase_first_last);
	MU_RUN_TEST(test_push_back);
	MU_RUN_TEST(test_pop_back);
	MU_RUN_TEST(test_resize_smaller);
	MU_RUN_TEST(test_resize_greater);
	MU_RUN_TEST(test_swap_method);
}

/*------------------------------------- No Member Functions -------------------------------------*/

void test_swap_no_member( void )
{
	IntVectorType v1;
	IntVectorType v2;
	bool test_result = false;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

	ft::swap(v1, v2);
	if (v1.size() == 3 && v1[0] == 4 && v1[1] == 5 && v1[2] == 6
		&& v2.size() == 3 && v2[0] == 1 && v2[1] == 2 && v2[2] == 3)
		test_result = true;
	/*
						Checking Iterators
	for (IntVectorType::iterator i1 = v1.begin(); i1 != v1.end(); i1++)
		std::cout << *i1 << ' ';
	for (IntVectorType::iterator i2 = v2.begin(); i2 != v2.end(); i2++)
		std::cout << *i2 << ' ';
	*/
	print_test("swap() [no member function]: ", test_result);
	mu_assert(test_result, "error, Something failed in Swapping");
}

void test_differ_operator_true( void )
{
	IntVectorType v1(5, 24);
	IntVectorType v2(5, 24);

	print_test("operator!= [false]: ", (v1 != v2) == false);
	mu_assert((v1 != v2) == false, "error, operator!= [false]");
}

void test_differ_operator_false( void )
{
	IntVectorType v1(5, 42);
	IntVectorType v2(5, 24);

	print_test("operator!= [true]: ", (v1 != v2) );
	mu_assert((v1 != v2), "error, operator!= [false]");
}

void test_equal_operator_true( void )
{
	IntVectorType v1(5, 24);
	IntVectorType v2(5, 24);

	print_test("operator== [true]: ", v1 == v2);
	mu_assert(v1 == v2, "error, operator== [true]");
}

void test_equal_operator_false( void )
{
	IntVectorType v1(5, 42);
	IntVectorType v2(5, 24);

	print_test("operator== [false]: ", (v1 == v2) == false);
	mu_assert((v1 == v2) == false, "error, operator== [false]");
}

void test_more_operator_true( void )
{
	IntVectorType v1(6, 24);
	IntVectorType v2(5, 24);

	print_test("operator> [true]: ", v1 > v2);
	mu_assert(v1 > v2, "error, operator> [true]");
}

void test_more_operator_false( void )
{
	IntVectorType v1(4, 24);
	IntVectorType v2(5, 24);

	print_test("operator> [false]: ", (v1 > v2) == false);
	mu_assert((v1 > v2) == false, "error, operato> [false]");
}

void test_more_equal_operator_true( void )
{
	IntVectorType v1(6, 24);
	IntVectorType v2(5, 24);

	print_test("operator>= [true]: ", v1 >= v2);
	mu_assert(v1 >= v2, "error, operator>= [true]");
}

void test_more_equal_operator_false( void )
{
	IntVectorType v1(4, 24);
	IntVectorType v2(5, 24);

	print_test("operator>= [false]: ", (v1 >= v2) == false);
	mu_assert((v1 >= v2) == false, "error, operator>= [false]");
}

void test_less_operator_true( void )
{
	IntVectorType v1(5, 24);
	IntVectorType v2(6, 24);

	print_test("operator< [true]: ", v1 < v2);
	mu_assert(v1 < v2, "error, operator< [true]");
}

void test_less_operator_false( void )
{
	IntVectorType v1(6, 24);
	IntVectorType v2(5, 24);

	print_test("operator< [false]: ", (v1 < v2) == false);
	mu_assert((v1 < v2) == false, "error, operator< [false]");
}

void test_less_equal_operator_true( void )
{
	IntVectorType v1(4, 24);
	IntVectorType v2(5, 24);

	print_test("operator<= [true]: ", v1 <= v2);
	mu_assert(v1 <= v2, "error, operator<= [true]");
}

void test_less_equal_operator_false( void )
{
	IntVectorType v1(6, 24);
	IntVectorType v2(5, 24);

	print_test("operator<= [false]: ", (v1 <= v2) == false);
	mu_assert((v1 <= v2) == false, "error, operator<= [false]");
}

MU_TEST_SUITE(vector_no_member_functions)
{
		std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR NO MEMBERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_swap_no_member);
	MU_RUN_TEST(test_equal_operator_true);
	MU_RUN_TEST(test_equal_operator_false);
	MU_RUN_TEST(test_differ_operator_true);
	MU_RUN_TEST(test_differ_operator_false);
	/* size and value counts */
	MU_RUN_TEST(test_more_operator_true);
	MU_RUN_TEST(test_more_operator_false);
	MU_RUN_TEST(test_more_equal_operator_true);
	MU_RUN_TEST(test_more_equal_operator_false);
	MU_RUN_TEST(test_less_operator_true);
	MU_RUN_TEST(test_less_operator_false);
	MU_RUN_TEST(test_less_equal_operator_true);
	MU_RUN_TEST(test_less_equal_operator_false);
}

int	vector_tests( void )
{
	MU_RUN_SUITE(vector_member_functions_tests);
	MU_RUN_SUITE(vector_element_access_tests);
	MU_RUN_SUITE(vector_iterators_tests);
	MU_RUN_SUITE(vector_capacity_tests);
	MU_RUN_SUITE(vector_modifiers_tests);
	MU_RUN_SUITE(vector_no_member_functions);

	MU_REPORT();
	return MU_EXIT_CODE;
}
