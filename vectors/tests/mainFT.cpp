/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/28 20:38:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

static void ft_str_vector_test(void)
{
	std::string s1[10] =	{"S1", "S2", "S3", "S4", "S5",
							"S6", "S7", "S8", "S9", "S10"};
	ft::vector<std::string> v1;

	testingModifiers(v1, s1);
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
