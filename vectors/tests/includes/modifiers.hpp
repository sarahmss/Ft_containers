/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:42:09 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/28 23:08:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP

#include "utils.hpp"

template<class container, typename T>
void	testingModifiers(container &v1, T type[10])
{
	ft::vector<std::string> v1_copy;

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
	std::cout << " | inserting 1 element at v1[2]: ";
	v1.insert((v1.begin() + 2), "I");
	printVector(v1, " v1");
	std::cout << " | inserting 3 element at v1[4]: ";
	v1.insert((v1.begin() + 4), 3 ,"I");
	printVector(v1, " v1");
	std::cout << " | inserting elements in range at v1_copy[0]: ";
	v1_copy.insert(v1_copy.begin(), v1.begin() + 4, v1.begin() + 7);
	printVector(v1_copy, " v1");
	std::cout << " | Clearing v1 copy!! " << std::endl;;
	v1_copy.clear();
	std::cout << " | erase inserted elements in v1: ";
	v1.erase(v1.begin() + 2);
	printVector(v1, " v1");
	std::cout << " | erase range of inserted elements in v1: ";
	v1.erase(v1.begin() + 3, v1.begin() + 6);
	printVector(v1, " v1");
}

#endif //MODIFIERS_HPP
