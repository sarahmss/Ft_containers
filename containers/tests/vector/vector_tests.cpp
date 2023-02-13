/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/13 01:19:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector_tests.hpp"

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

void	test_get_allocator()
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

int	vector_tests( void )
{
	MU_RUN_SUITE(vector_member_functions_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
