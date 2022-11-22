/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:42:09 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/21 23:28:39 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP

#include "utils.hpp"

template<class container>
void	testingModifiers(const container &vector)
{
	std::cout << "------ Modifiers --------" << std::endl;
	std::cout << "poping_back() 5 elements" << std::endl;
	for (size_t i = 0; i < 5; i++)
		vector.pop_back();
	std::cout << "using assignement operator" << std::endl;
	container::v1_copy = v1;
	printVector(v1_copy);
}

#endif //MODIFIERS_HPP
