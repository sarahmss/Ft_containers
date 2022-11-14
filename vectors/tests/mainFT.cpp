/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/14 17:38:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

int main( void )
{
	ft::vector<std::string>				ft_str_vector;

	ft_str_vector.push_back("Position 0");
	ft_str_vector.push_back("Position 1");

	std::cout << "----------- instanciating str vector --------------" << std::endl;
	printVector(ft_str_vector);
	testingOperators(ft_str_vector);
	testingCapacity(ft_str_vector);
	testingIterators(ft_str_vector);
	return (0);
}
