/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/13 18:07:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

int main( void )
{
	ft::vector<std::string>		ft_str_vector;

	ft_str_vector.push_back("Position 0");
	ft_str_vector.push_back("Position 1");

	testingOperators(ft_str_vector);
	testingCapacity(ft_str_vector);
	return (0);
}
