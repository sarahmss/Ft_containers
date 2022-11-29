/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:04:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/28 16:20:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "./tests.hpp"
#include <iomanip>


template <class container>
void	printVector (const container &vector, std::string vecName)
{
	std::cout << vecName << " [ ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << "]" << std::endl;
}
#endif //UTILS_HPP
