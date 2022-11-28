/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/28 17:28:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

static void ft_str_vector_test(void)
{
	std::string s1[10] =	{"v1_S1", "v1_S2", "v1_S3", "v1_S4", "v1_S5",
							"v1_S6", "v1_S7", "v1_S8", "v1_S9", "v1_S10"};
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
