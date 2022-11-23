/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/22 21:34:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

static void ft_str_vector_test(void)
{
	ft::vector<std::string> v1;
	std::string s1[10] =	{"v1_S1", "v1_S2", "v1_S3", "v1_S4", "v1_S5",
							"v1_S6", "v1_S7", "v1_S8", "v1_S9", "v1_S10"};

	std::cout << "------ Modifiers --------" << std::endl;
	std::cout << " | Pushing 10 elements:";
	for (int i = 0; i < 10; i++)
			v1.push_back(s1[i]);
	printVector(v1);
	std::cout << " | Poping 5 elements:";
	for (size_t i = 0; i < 5; i++)
		v1.pop_back();
	printVector(v1);
/*	std::cout << " | using = to make a copy:";
	ft::vector<std::string> v1_copy = v1;
	printVector(v1_copy);*/
	testingCapacity(v1);
	testingIterators(v1);
	testingOperators(v1, v1);
	testingElementAccess(v1);
}

int main(void)
{
	ft_str_vector_test();
	return (0);
}
