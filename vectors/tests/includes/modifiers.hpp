/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:42:09 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/28 17:59:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP

#include "utils.hpp"

template<class container, typename T>
void	testingModifiers(container &v1, T type[10])
{
	ft::vector<std::string> v1_copy;
	ft::vector<std::string>::iterator it;

	std::cout << "------ Modifiers --------" << std::endl;
	std::cout << " | Pushing 10 elements: ";
	for (int i = 0; i < 10; i++)
			v1.push_back(type[i]);
	printVector(v1, "v1");
	std::cout << " | Poping 5 elements: ";
	for (size_t i = 0; i < 5; i++)
		v1.pop_back();
	printVector(v1, "v1");
	std::cout << " | using = to make a copy: ";
	v1_copy = v1;
	printVector(v1_copy, "v1 copy");
	std::cout << " | Clearing v1 copy: " << std::endl;;
	v1_copy.clear();
	std::cout << " | inserting 1 element at v1[2]: " << std::endl;;
	it = v1.begin();
	it += 2;
	v1.insert(it, "Inserted");
	printVector(v1, "v1");
}

#endif //MODIFIERS_HPP
