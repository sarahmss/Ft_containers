/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:53:05 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/30 16:24:11 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/pair.hpp"
#include "./utils/bidirectionalIterator.hpp"
#include "./utils/reverseIterator.hpp"


namespace ft
{
	template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef ft::pair<const key_type, mapped_type>											value_type;
			typedef std::size_t																		size_type;
			typedef std::ptrdiff_t																	diferrence_type;
			typedef Compare																			key_compare;
			typedef Allocator																		allocator_type;
			typedef typename allocator_type::reference												reference;
			typedef typename allocator_type::const_reference										const_reference;
			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer											const_pointer;
			typedef typename ft::bidirectional_iterator<value_type, allocator_type, key_compare>	iterator;
			typ ft::reverse_iterator<iterator>														reverse_iterator;
			typ ft::reverse_iterator<const_iterator>												const_reverse_iterator;
	}
}

#endif //MAP_HPP

