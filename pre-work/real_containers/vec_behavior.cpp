/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_behavior.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:35:42 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/28 16:50:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <string>
#include <memory>

template <class container>
void	printVector (const container &vector, std::string vecName)
{
	std::cout << vecName << " [ ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << "]" << std::endl;
}

static void ft_str_vector_test(void)
{
	//std::vector<std::string> v1 = {"A", "B", "C", "D", "E", "F"};
	std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}

int main(void)
{
	ft_str_vector_test();
	return (0);
}

