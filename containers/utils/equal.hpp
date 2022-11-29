/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:06 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/16 20:47:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

/*
	@brief
		Returns true if the range [first1, last1)
		is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.
	@param
		first1, last1 	- 	the first range of the elements to compare
		first2, last2 	- 	the second range of the elements to compare
*/

namespace ft {
template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1,
			InputIt2 first2)
{
	while (first1 != last1) {
		if (!(*first1 == *first2)) {
			return false;
		}
		++first1;
		++first2;
	}
	return true;
}
}
#endif //EQUAL_HPP
