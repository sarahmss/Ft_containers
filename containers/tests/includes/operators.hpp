/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:00:38 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/21 22:46:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "utils.hpp"

template<class container>
void	testingOperators(const container &vector1, const container &vector2)
{
	std::cout << "-------- Operators --------" << std::endl;
	std::cout	<< " | vec1 == vec2 " << (vector1 == vector2 ? TRUE : FALSE)
				<< " |\n | vec1 != vec2 " << (vector1 != vector2 ? TRUE : FALSE)
				<< "|\n | vec1 >= vec2 " << (vector1 <= vector2 ? TRUE : FALSE)
				<< "|\n | vec1 <= vec2 " << (vector1 >= vector2 ? TRUE : FALSE)
				<< "|\n | vec1 > vec2  " << (vector1 < vector2 ? TRUE : FALSE)
				<< "|\n | vec1 < vec2  " << (vector1 > vector2 ? TRUE : FALSE) << "|\n";
}
#endif //OPERATORS_HPP
