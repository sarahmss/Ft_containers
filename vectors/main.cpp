/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/13 16:07:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

template <typename T>
void	printVector (const ft::vector<T> &vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl << "----------------------" << std::endl;
}

int main( void )
{
	ft::vector<std::string>		vector;

	vector.push_back("Creating");
	vector.push_back("Vector");
	printVector<std::string>(vector);

	return (0);
}
