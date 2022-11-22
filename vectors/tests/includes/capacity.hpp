/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:52:11 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/21 22:52:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPACITY_HPP
#define CAPACITY_HPP

#include "utils.hpp"

template<class container>
void	testingCapacity(const container &vector)
{
	std::cout << "----- Capacity ------" << std::endl;
	std::cout	<< " | Size:     " << vector.size()
				<< "    |\n | Empty:  " << (vector.empty() ? TRUE : FALSE)
				<< " |\n | Capacity: " << vector.capacity() << "    |" << std::endl;
}

#endif //CAPACITY_HPP
