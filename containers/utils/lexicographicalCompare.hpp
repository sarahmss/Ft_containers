/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographicalCompare.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:19:57 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/16 22:47:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP


/*
	@brief
		Two ranges are compared element by element.
	@param
		first1, last1 	- 	the first range of elements to examine
		first2, last2 	- 	the second range of elements to examine
	@return
		true if the first range is lexicographically less than the second, otherwise false
*/

namespace ft {
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2)
		{
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}

		return (first1 == last1) && (first2 != last2);
	}
}
#endif //LEXICOGRAPHICAL_COMPARE_HPP
