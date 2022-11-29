/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:48:38 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/29 16:51:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <vector>

/*
	@brief:
		pair is a class template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.
	@param
		T1, T2 	- 	the types of the elements that the pair stores.
*/

namespace ft
{
	<template class T1, class T2>
	struct pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair (void) : first(first_type()), second(second_type()) {};

			template <class x, class y>
			pair(const pair<x,y> &pr) :  first(pr.first), second(pr.second){};

			pair (const first_type &x, const second_type &y) : first(x), second(y){};

			pair  &operator=(const pair &rhs)
			{
				this->first = rhs.first;
				this->second = rhs.second;
				return (*this);
			}
	}
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
  	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs==rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return lhs.first < rhs.first || ((rhs.first == lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return rhs < lhs;
	}

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return ! (lhs < rhs);
	}

	template < class T1,class T2 >
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return ( pair< T1, T2 >(x, y) );
	}
}
#endif //PAIR_HPP
