/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:04:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/13 17:20:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "./tests.hpp"

template <typename T>
void	printVector (const ft::vector<T> &vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
}
#endif //UTILS_HPP
