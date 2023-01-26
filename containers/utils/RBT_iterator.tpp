/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:29:58 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 22:46:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATORS_TPP
#define RBT_ITERATORS_TPP

#include "RBT.hpp"

namespace ft {

	template <RBT_TEMPLATE>
	typename RBT_CLASS::iterator RBT_CLASS::begin( void )
	{
		return (iterator(minimum(root)));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::const_iterator RBT_CLASS::begin( void ) const
	{
		return (const_iterator(minimum(root)));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::iterator RBT_CLASS::end( void )
	{
		return (iterator(TNULL));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::const_iterator RBT_CLASS::end( void ) const
	{
		return (const_iterator(TNULL));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::reverse_iterator RBT_CLASS::rbegin( void )
	{
		return (reverse_iterator(TNULL));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::const_reverse_iterator RBT_CLASS::rbegin( void ) const
	{
		return (const_reverse_iterator(TNULL));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::reverse_iterator RBT_CLASS::rend( void )
	{
		return (reverse_iterator(begin()));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::const_reverse_iterator RBT_CLASS::rend( void ) const
	{
		return (const_reverse_iterator(begin()));
	}
}
#endif
