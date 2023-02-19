/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/19 14:19:56 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_tests.hpp"
/*------------------------------- Member function ------------------------------------------------*/
void	test_stack_default_constr( void )
{
	IntStackType		s1;
	bool				test_result = s1.empty();

	print_test("Instanciating default constructor: ", test_result);
	mu_assert(test_result == true, "error, stack_default_constr");
}

void	test_stack_copy_constructor( void )
{
	IntStackType s1;
	s1.push(42);
	s1.push(42);;
;
	IntStackType s2(s1);
	bool	test_result = s1 == s2;

	print_test("Instanciating copy constructor: ", test_result);
	mu_assert(test_result == true, "error, stack_copy_constr");
}

void	test_stack_assignment_operator( void )
{
	IntStackType s1;
	s1.push(42);
	s1.push(42);;
;
	IntStackType s2 = s1;
	bool	test_result = s1 == s2;

	print_test("operator=(): ", test_result);
	mu_assert(test_result == true, "error, operator=()");
}


MU_TEST_SUITE(stack_member_functions_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING STACK MEMBER FUNCTIONS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_stack_default_constr);
	MU_RUN_TEST(test_stack_copy_constructor);
	MU_RUN_TEST(test_stack_assignment_operator);
}

/*------------------------------- Element access ------------------------------------------------*/

void	test_stack_access_top( void )
{
	IntStackType s1;
	bool	test_result = true;

	s1.push(42);
	if (s1.top() != 42)
		test_result = false;
	s1.push(4242);
	if (s1.top() != 4242)
		test_result = false;

	print_test("top(): ", test_result);
	mu_assert(test_result == true, "error, top()");
}


/*------------------------------------- Capacity ------------------------------------------------*/

void	test_stack_size( void )
{
	IntStackType	s1;
	for (int i = 0; i < 5; i++)
		s1.push(42);
;
	print_test("size(): ", s1.size() == 5);
	mu_assert(s1.size() == 5, "error, wrong size()");
}

void	test_stack_empty( void )
{
	IntStackType			s1;

	print_test("empty() [empty stack]: ", s1.empty());
	mu_assert(s1.empty(), "error, empty() method");
}

void	test_stack_not_empty( void )
{
	IntStackType	s1;
	s1.push(42);
	bool			test_result = s1.empty() == false;

	print_test("empty() [not empty stack]: ", test_result);
	mu_assert(test_result == true, "error, empty() method");
}


MU_TEST_SUITE(stack_capacity_tests)
{
		std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING STACK CAPACITY TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_stack_empty);
	MU_RUN_TEST(test_stack_not_empty);
	MU_RUN_TEST(test_stack_size);
}

MU_TEST_SUITE(stack_element_access_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING STACK ELEMENT ACCESS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_stack_access_top);
}

/*------------------------------------- Modifiers ------------------------------------------------*/

void	test_stack_pop( void )
{
	IntStackType	s1;
	bool			test_result = true;
	for (int i = 0; i < 5; i++)
		s1.push(42);
	for (int i = 0; i < 5; i++)
	{
		s1.pop();
		if ((int)s1.size() != 4 - i)
			test_result = false;
	}
	print_test("pop(): ", test_result);
	mu_assert(test_result == true, "error, pop() method");
}

void	test_stack_push( void )
{
	IntStackType	s1;
	bool			test_result = true;
	for (int i = 0; i < 5; i++)
		s1.push(42 + i);
	if (s1.top() != 46)
		test_result = false;
	print_test("push(): ", test_result);
	mu_assert(test_result == true, "error, push() method");
}

MU_TEST_SUITE(stack_modifiers_tests)
{
	std::cout	<< std::endl << std::setw(60)
				<< "\033[1;34m[RUNNING STACK MODIFIERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_stack_push);
	MU_RUN_TEST(test_stack_pop);
}



/*------------------------------------- No Member Functions -------------------------------------*/

void test_stack_differ_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(42);

	print_test("operator!= [false]: ", (s1 != s2) == false);
	mu_assert((s1 != s2) == false, "error, operator!= [false]");
}
void test_stack_differ_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(45);

	print_test("operator!= [true]: ", (s1 != s2));
	mu_assert((s1 != s2), "error, operator!= [true]");
}

void test_stack_equal_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(42);

	print_test("operator== [true]: ", s1 == s2);
	mu_assert(s1 == s2, "error, operator== [true]");
}

void test_stack_equal_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(45);

	print_test("operator== [false]: ", (s1 == s2) == false);
	mu_assert((s1 == s2) == false, "error, operator== [false]");
}

void test_stack_more_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(43);
	s2.push(42);

	print_test("operator> [true]: ", s1 > s2);
	mu_assert(s1 > s2, "error, operator> [true]");
}

void test_stack_more_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(43);

	print_test("operator> [false]: ", (s1 > s2) == false);
	mu_assert((s1 > s2) == false, "error, operato> [false]");
}

void test_stack_more_equal_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(43);
	s2.push(43);

	print_test("operator>= [true]: ", s1 >= s2);
	mu_assert(s1 >= s2, "error, operator>= [true]");
}

void test_stack_more_equal_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(43);

	print_test("operator>= [false]: ", (s1 >= s2) == false);
	mu_assert((s1 >= s2) == false, "error, operator>= [false]");
}

void test_stack_less_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(43);

	print_test("operator< [true]: ", s1 < s2);
	mu_assert(s1 < s2, "error, operator< [true]");
}

void test_stack_less_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(43);
	s2.push(42);

	print_test("operator< [false]: ", (s1 < s2) == false);
	mu_assert((s1 < s2) == false, "error, operator< [false]");
}


void test_stack_less_equal_operator_true( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(42);
	s2.push(43);

	print_test("operator<= [true]: ", s1 <= s2);
	mu_assert(s1 <= s2, "error, operator<= [true]");
}

void test_stack_less_equal_operator_false( void )
{
	IntStackType	s1;
	IntStackType	s2;

	s1.push(43);
	s2.push(42);

	print_test("operator<= [false]: ", (s1 <= s2) == false);
	mu_assert((s1 <= s2) == false, "error, operator<= [false]");
}

MU_TEST_SUITE(stack_no_member_functions)
{
		std::cout	<< std::endl << std::setw(65)
				<< "\033[1;34m[RUNNING VECTOR NO MEMBERS TESTS]\033[0m" << std::endl;
	MU_RUN_TEST(test_stack_differ_operator_true);
	MU_RUN_TEST(test_stack_differ_operator_false);
	MU_RUN_TEST(test_stack_equal_operator_true);
	MU_RUN_TEST(test_stack_equal_operator_false);
	MU_RUN_TEST(test_stack_more_operator_true);
	MU_RUN_TEST(test_stack_more_operator_false);
	MU_RUN_TEST(test_stack_more_equal_operator_true);
	MU_RUN_TEST(test_stack_more_equal_operator_false);
	MU_RUN_TEST(test_stack_less_operator_true);
	MU_RUN_TEST(test_stack_less_operator_false);
	MU_RUN_TEST(test_stack_less_equal_operator_true);
	MU_RUN_TEST(test_stack_less_equal_operator_false);
}


int	stack_tests( void )
{
	MU_RUN_SUITE(stack_member_functions_tests);
	MU_RUN_SUITE(stack_element_access_tests);
	MU_RUN_SUITE(stack_capacity_tests);
	MU_RUN_SUITE(stack_modifiers_tests);
	MU_RUN_SUITE(stack_no_member_functions);

	MU_REPORT();
	return MU_EXIT_CODE;
}
