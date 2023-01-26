/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:20:48 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/26 17:13:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iterator>

/*
	Iterator traits class defining properties of iterators.
*/

namespace ft {

	/*
		iterator_traits obtains information
		from Iterator class in template argument.
	*/
	template <class T>
	struct iterator_traits {
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
	};

	/*
		This create a default operation with an
		object (first argument in template argument).
	*/
	template <typename T>
	struct iterator_traits<T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::ptrdiff_t					difference_type;
	};
	/*
		This create a default operation with an const
		object (first argument in template argument).
	*/
	template <class T>
	class iterator_traits<const T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::ptrdiff_t					difference_type;
	};
}

#endif //ITERATOR_TRAITS_HPP
