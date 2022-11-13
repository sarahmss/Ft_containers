/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:04:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/13 17:54:56 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "./tests.hpp"

template <class container>
void	printVector (const container &vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
}
#endif //UTILS_HPP
