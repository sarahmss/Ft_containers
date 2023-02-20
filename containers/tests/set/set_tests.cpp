/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/19 22:58:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./set_tests.hpp"
/*------------------------------- Member function ------------------------------------------------*/
void	test_set_default_constr( void )
{
	IntSetType		s1;
	bool			test_result = s1.empty();

	print_test("Instanciating default constructor: ", test_result);
	mu_assert(test_result == true, "error, set_default_constr");
}

void	test_set_range_constr( void )
{
	IntSetType s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);

	IntSetType s2(s1.begin(), s1.end());
	bool	test_result = s1 == s2;

	print_test("Instanciating range constructor: ", test_result);
	mu_assert(test_result == true, "error, set_range_constr");
}

void	test_set_copy_constructor( void )
{
	IntSetType s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);

	IntSetType s2(s1);
	bool	test_result = s1 == s2;

	print_test("Instanciating copy constructor: ", test_result);
	mu_assert(test_result == true, "error, set_copy_constr");
}

void	test_set_assignment_operator( void )
{
	IntSetType s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);

	IntSetType s2 = s1;
	bool	test_result = s1 == s2;

	print_test("operator=() [s1==s2]: ", test_result);
	mu_assert(test_result == true, "error, operator=()");
}

void	test_set_get_allocator( void )
{
	IntSetType		s1;

	IntSetType::allocator_type alloc1 = s1.get_allocator();
	print_test("get_allocator(): ", true);
	mu_assert(true, "error, incorrect allocator type");
}

MU_TEST_SUITE(set_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_default_constr);
 	MU_RUN_TEST(test_set_range_constr);
	MU_RUN_TEST(test_set_copy_constructor);
	MU_RUN_TEST(test_set_assignment_operator);
	MU_RUN_TEST(test_set_get_allocator);
}

/*------------------------------- Iterators ------------------------------------------------*/

void	test_set_begin_iterator( void ) // increment from begin to end
{
	IntSetType s1;
	s1.insert(42);
	s1.insert(4242);
	IntSetType::iterator begin = s1.begin();
	bool	test_result = true;

	if (*begin != 42 || *(++begin) != 4242)
		test_result = false;
	print_test("begin()  [pre-increment it]: ", test_result);
	mu_assert(test_result, "error, wrong begin iterator");
}

void	test_set_rbegin_iterator( void ) //increment from end to begin0.00054603
{
	IntSetType s1;
	s1.insert(42);
	s1.insert(4242);
	IntSetType::reverse_iterator rbegin = s1.rbegin();
	bool	test_result = true;

	if (*rbegin != 4242 || *(++rbegin) != 42)
		test_result = false;
	print_test("rbegin() [pre-increment rev_it]: ", test_result);
	mu_assert(test_result, "error, wrong rbegin iterator");
}

void	test_set_end_iterator( void ) // decrement from end to begin
{
	IntSetType s1;
	s1.insert(42);
	s1.insert(4242);
	IntSetType::iterator end = s1.end();
	bool	test_result = true;

	if (*(--end) != 4242 || *(--end) != 42)
		test_result = false;
	print_test("end() [pre-decrement it]: ", test_result);
	mu_assert(test_result, "error, wrong end iterator");
}

void	test_set_rend_iterator( void ) // decrement from begin to end
{
	IntSetType s1;
	s1.insert(42);
	s1.insert(4242);
	IntSetType::reverse_iterator rend = s1.rend();
	bool	test_result = true;

	if (*(--rend) != 42 || *(--rend) != 4242)
		test_result = false;
	print_test("rend() [pre-decrement rev-it]: ", test_result);
	mu_assert(test_result, "error, wrong rend iterator");
}

MU_TEST_SUITE(set_iterators_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET ITERATORS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_begin_iterator);
	MU_RUN_TEST(test_set_rbegin_iterator);
	MU_RUN_TEST(test_set_end_iterator);
	MU_RUN_TEST(test_set_rend_iterator);
}

/*------------------------------------- Capacity ------------------------------------------------*/

void	test_set_max_size( void )
{
	IntSetType			s1;
	bool				test_result = s1.max_size();

	print_test("max_size(): ", test_result);
	mu_assert(test_result, "error, wrong max_size()");
}

void	test_set_size( void )
{
	IntSetType	s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	bool			test_result = s1.size() == 5;

	print_test("size() [5 elements]: ", test_result);
	mu_assert(test_result == true, "error, wrong size()");
}

void	test_set_empty( void )
{
	IntSetType	s1;
	bool		test_result = s1.empty();

	print_test("empty() [empty set]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

void	test_set_not_empty( void )
{
	IntSetType	s1;
	s1.insert(42);
	bool			test_result = s1.empty() == false;

	print_test("empty() [not empty set]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}

MU_TEST_SUITE(set_capacity_tests)
{
		std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET CAPACITY TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_empty);
	MU_RUN_TEST(test_set_not_empty);
	MU_RUN_TEST(test_set_size);
	MU_RUN_TEST(test_set_max_size);
}
/*------------------------------------- Modifiers ------------------------------------------------*/

void	test_set_swap_method( void )
{
	IntSetType s1;
	IntSetType s2;
	bool test_result = false;

	s1.insert(1);
	s1.insert(2);
	s2.insert(4);
	s2.insert(5);
	s1.swap(s2);

	if (s1.size() == 2 && *s1.begin() == 4 && *(--s1.end()) == 5
		&& s2.size() == 2 && *s2.begin() == 1 && *(--s2.end()) == 2)
		test_result = true;
	print_test("swap() [method]: ", test_result);
	mu_assert(test_result, "error, Something failed in Swapping");
}

void	test_set_clear( void )
{
	IntSetType	s1;
	s1.insert(1);
	s1.insert(2);
	s1.clear();
	bool			test_result = s1.empty();

	print_test("clear()[size()=2]: ", test_result);
	mu_assert(test_result == true, "error, clear() method");
}

void	test_set_insert_value( void )
{
	IntSetType			s1;
	s1.insert(1);
	bool	test_result = true;

	if (*s1.begin() != 1)
		test_result = false;
	print_test("insert(value): ", test_result);
	mu_assert(test_result == true, "error, insert(value) method");
}

void	test_set_insert_pos_value( void )
{
	IntSetType				s1;
	bool					test_result = true;

	s1.insert(1);
	s1.insert(s1.begin(), 2);
	if (*(--s1.end()) != 2)
		test_result = false;
	print_test("insert(pos, value): ", test_result);
	mu_assert(test_result == true, "error, insert(pos, value) method");
}

void	test_set_insert_first_last( void )
{
	IntSetType	s2;
	IntSetType	s1;
	bool		test_result;

	s1.insert(1);
	s1.insert(2);
	s2.insert(s1.begin(), s1.end());
	test_result = s1 == s2;

	print_test("insert(first, last): ", test_result);
	mu_assert(test_result == true, "error, insert(first, last) method");
}

void	test_set_erase_key( void )
{
	IntSetType				s1;
	bool					test_result = true;

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.erase(1);
	if (s1.size() != 2 || *s1.begin() != 2 || *(--s1.end()) != 3)
		test_result = false;
	print_test("erase(key): ", test_result);
	mu_assert(test_result, "error, erase(key) method");
}

void	test_set_erase_pos( void )
{
	IntSetType				s1;
	bool					test_result = true;

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.erase(*(--s1.end()));
	if (s1.size() != 2 || *s1.begin() != 1 || *(--s1.end()) != 2)
		test_result = false;
	print_test("erase(pos): ", test_result);
	mu_assert(test_result, "error, erase(pos) method");
}

void	test_set_erase_first_last( void )
{
	IntSetType	s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.erase(s1.begin(), s1.end());
	bool		test_result = s1.empty();

	print_test("erase(first, last): ", test_result);
	mu_assert(test_result == true, "error, erase(first, last) method");
}

MU_TEST_SUITE(set_modifiers_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET MODIFIERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_clear);
	MU_RUN_TEST(test_set_insert_value);
	MU_RUN_TEST(test_set_insert_pos_value);
	MU_RUN_TEST(test_set_insert_first_last);
	MU_RUN_TEST(test_set_erase_key);
	MU_RUN_TEST(test_set_erase_pos);
	MU_RUN_TEST(test_set_erase_first_last);
	MU_RUN_TEST(test_set_swap_method);
}


/*------------------------------------- Lookup ------------------------------------------------*/

void	test_set_count( void )
{
	IntSetType			s1;
	bool				test_result = true;

	s1.insert(4242);
	if (s1.count(4242) != 1 || s1.count(42) != 0)
		test_result = false;
	print_test("count(): ", test_result);
	mu_assert(test_result == true, "error, count() method");
}

void	test_set_find( void )
{
	IntSetType					s1;
	bool						test_result = true;
	IntSetType::iterator		it;

	s1.insert(42);
	it = s1.find(42);

	if (it != s1.begin() || *it != 42)
		test_result = false;
	print_test("find(): ", test_result);
	mu_assert(test_result == true, "error, find() method");
}

void	test_set_equal_range( void ) /*returns a pair of element + next_element*/
{
	IntSetType	s1;
	bool		test_result = true;

	s1.insert(42);
	s1.insert(4242);
	s1.insert(424242);

	ft::pair<IntSetType::const_iterator, IntSetType::const_iterator> range1 = s1.equal_range(42);
	ft::pair<IntSetType::const_iterator, IntSetType::const_iterator> range2 = s1.equal_range(4242);
	ft::pair<IntSetType::const_iterator, IntSetType::const_iterator> range3 = s1.equal_range(424242);

	if (*range1.first != 42 || *range1.second != 4242
		|| *range2.first != 4242 || *range2.second != 424242
		|| *range3.first != 424242 || *range3.second > 424242)
		test_result = false;
	print_test("equal_range(): ", test_result);
	mu_assert(test_result == true, "error, equal_range() method");
}

void	test_set_lower_bound( void )
{
	IntSetType	s1;
	bool		test_result = true;

	s1.insert(42);
	s1.insert(4242);
	s1.insert(424242);

	IntSetType::iterator lower1 = s1.lower_bound(42);
	IntSetType::iterator lower2 = s1.lower_bound(4242);
	IntSetType::iterator lower3 = s1.lower_bound(424242);
	IntSetType::iterator lower4 = s1.lower_bound(0);

	if  (*lower1 != 42 || *lower2 != 4242 || *lower3 != 424242 || lower4 != s1.begin())
		test_result = false;
	print_test("lower_bound(): ", test_result);
	mu_assert(test_result == true, "error, lower_bound() method");
}

void	test_set_upper_bound( void )
{
	IntSetType	s1;
	bool		test_result = true;

	s1.insert(42);
	s1.insert(4242);
	s1.insert(424242);

	IntSetType::iterator upper1 = s1.upper_bound(42);
	IntSetType::iterator upper2 = s1.upper_bound(4242);

	if (*upper1 != 4242 || *upper2 != 424242)
		test_result = false;
	print_test("upper_bound(): ", test_result);
	mu_assert(test_result == true, "error, upper_bound() method");
}

MU_TEST_SUITE(set_lookup_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET LOOKUP TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_count);
	MU_RUN_TEST(test_set_find);
	MU_RUN_TEST(test_set_equal_range);
	MU_RUN_TEST(test_set_upper_bound);
	MU_RUN_TEST(test_set_lower_bound);

}


/*------------------------------------- Observers ------------------------------------------------*/

void	test_set_key_comp( void )
{
	IntSetType	s1;
	bool		test_result = true;

	s1.insert(42);
	s1.insert(43);

	IntSetType::key_compare	my_key_comp = s1.key_comp();
	if (my_key_comp(42, 43) != true || my_key_comp(42, 42) != false)
		test_result = false;
	print_test("key_comp(): ", test_result);
	mu_assert(test_result == true, "error, key_comp() method");
}

void	test_set_value_comp( void )
{
	IntSetType	s1;
	bool		test_result = true;

	s1.insert(42);
	s1.insert(43);
	IntSetType::iterator		it = s1.begin();
	IntSetType::value_compare	my_value_comp = s1.value_comp();

	for (; my_value_comp(*it, 43); ++it) // element smaller than 43
		if (*it != 42 )
			test_result = false;
	print_test("value_comp(): ", test_result);
	mu_assert(test_result == true, "error, value_comp() method");

}

MU_TEST_SUITE(set_observers_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING SET OBSERVERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_key_comp);
	MU_RUN_TEST(test_set_value_comp);
}



/*------------------------------------- No Member Functions -------------------------------------*/

void test_set_differ_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(42);

	print_test("operator!= [false]: ", (s1 != s2) == false);
	mu_assert((s1 != s2) == false, "error, operator!= [false]");
}
void test_set_differ_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(4242);

	print_test("operator!= [true]: ", (s1 != s2));
	mu_assert((s1 != s2), "error, operator!= [true]");
}

void test_set_equal_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(42);

	print_test("operator== [true]: ", s1 == s2);
	mu_assert(s1 == s2, "error, operator== [true]");
}

void test_set_equal_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(4242);

	print_test("operator== [false]: ", (s1 == s2) == false);
	mu_assert((s1 == s2) == false, "error, operator== [false]");
}

void test_set_more_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(52);
	s2.insert(42);

	print_test("operator> [true]: ", s1 > s2);
	mu_assert(s1 > s2, "error, operator> [true]");
}

void test_set_more_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(42);

	print_test("operator> [false]: ", (s1 > s2) == false);
	mu_assert((s1 > s2) == false, "error, operato> [false]");
}

void test_set_more_equal_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(42);

	print_test("operator>= [true]: ", s1 >= s2);
	mu_assert(s1 >= s2, "error, operator>= [true]");
}

void test_set_more_equal_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(32);
	s2.insert(42);

	print_test("operator>= [false]: ", (s1 >= s2) == false);
	mu_assert((s1 >= s2) == false, "error, operator>= [false]");
}

void test_set_less_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(32);
	s2.insert(42);

	print_test("operator< [true]: ", s1 < s2);
	mu_assert(s1 < s2, "error, operator< [true]");
}

void test_set_less_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(32);

	print_test("operator< [false]: ", (s1 < s2) == false);
	mu_assert((s1 < s2) == false, "error, operator< [false]");
}


void test_set_less_equal_operator_true( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(42);
	s2.insert(42);

	print_test("operator<= [true]: ", s1 <= s2);
	mu_assert(s1 <= s2, "error, operator<= [true]");
}

void test_set_less_equal_operator_false( void )
{
	IntSetType	s1;
	IntSetType	s2;

	s1.insert(52);
	s2.insert(42);

	print_test("operator<= [false]: ", (s1 <= s2) == false);
	mu_assert((s1 <= s2) == false, "error, operator<= [false]");
}

MU_TEST_SUITE(set_no_member_functions)
{
		std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR NO MEMBERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_set_differ_operator_true);
	MU_RUN_TEST(test_set_differ_operator_false);
	MU_RUN_TEST(test_set_equal_operator_true);
	MU_RUN_TEST(test_set_equal_operator_false);
	MU_RUN_TEST(test_set_more_operator_true);
	MU_RUN_TEST(test_set_more_operator_false);
	MU_RUN_TEST(test_set_more_equal_operator_true);
	MU_RUN_TEST(test_set_more_equal_operator_false);
	MU_RUN_TEST(test_set_less_operator_true);
	MU_RUN_TEST(test_set_less_operator_false);
	MU_RUN_TEST(test_set_less_equal_operator_true);
	MU_RUN_TEST(test_set_less_equal_operator_false);
}

int	set_tests( void )
{
	MU_RUN_SUITE(set_member_functions_tests);
	MU_RUN_SUITE(set_iterators_tests);
	MU_RUN_SUITE(set_capacity_tests);
	MU_RUN_SUITE(set_modifiers_tests);
	MU_RUN_SUITE(set_lookup_tests);
	MU_RUN_SUITE(set_observers_tests);
	MU_RUN_SUITE(set_no_member_functions);
	MU_REPORT();
	return MU_EXIT_CODE;
}
