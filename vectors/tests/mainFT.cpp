/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/21 23:08:46 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

static void ft_str_vector_test( void )
{
	ft::vector<std::string>	ft_str_vector;
	std::string	s1[15] =	{"S1", "S2", "S3", "S4", "S5",
							"S6", "S7", "S8", "S9", "S10",
							"S11", "S12", "S13", "S14", "S15"};

	std::cout << "----------- instanciating str vector --------------" << std::endl;
	for (size_t i = 0; i < 15; i++)
		ft_str_vector.push_back(s1[i]);
	printVector(ft_str_vector);
	testingCapacity(ft_str_vector);
	testingIterators(ft_str_vector);
	testingOperators(ft_str_vector, ft_str_vector);
	testingElementAccess(ft_str_vector);
}

int main( void )
{
	ft_str_vector_test();
	return (0);
}
