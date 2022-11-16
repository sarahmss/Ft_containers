/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:41:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/16 00:44:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "utils.hpp"

template<class container>
void	testingIterators(const container &vector)
{
	std::cout << "----------------- Iterators -------------------" << std::endl;
	std::cout	<< " | begin: " << *vector.begin()
				<< " | end: " << *(vector.end() - 1)
				<< " | rbegin: " << *vector.rbegin()
				<< " | rend: " << *(vector.rend() - 1)
				<< " |" << std::endl;
}

#endif //ITERATORS_HPP
