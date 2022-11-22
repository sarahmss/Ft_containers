/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:41:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/21 23:08:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "utils.hpp"

template<class container>
void	testingIterators(const container &vector)
{
	std::cout	<< "------ Iterators -----\n"
				<< " | begin:"		<< std::setw(9) << *vector.begin()
				<< " |\n | end:"	<< std::setw(11) << *(vector.end() - 1)
				<< " |\n | rbegin:"	<< std::setw(8) << *vector.rbegin()
				<< " |\n | rend:"	<< std::setw(10) << *(vector.rend() - 1)
				<< " | " << std::endl;
}

#endif //ITERATORS_HPP
