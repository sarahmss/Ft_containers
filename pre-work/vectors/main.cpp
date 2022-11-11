/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:24:36 by coder             #+#    #+#             */
/*   Updated: 2022/11/10 05:20:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ft_vector.hpp"

template <typename T>
void	printVector (const ft_vector<T> &vector)
{
	for (size_t i = 0; i < vector.getSize(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl << "----------------------" << std::endl;		
}

int main( void )
{
	ft_vector<std::string>		vector;

	vector.PushBack("Creating");
	vector.PushBack("Vector");
	printVector<std::string>(vector);

	return (0);
}
