/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:00:38 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/13 17:29:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "utils.hpp"

// access specified element
template<typename T>
void	Squarebrackets( const ft::vector<T> &vector )
{
	std::cout << "---------- Operator [] -----------" << std::endl;
	try {
		std::cout << " Read at [-1] pos : " << vector[-1] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << " Read at [0] pos : " << vector[0] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

template<typename T>
void	testingOperators(const ft::vector<T> &vector)
{
	Squarebrackets(vector);
}


#endif //OPERATORS_HPP
