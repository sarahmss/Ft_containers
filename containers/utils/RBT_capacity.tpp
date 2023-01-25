/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_capacity.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:31:14 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 18:58:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_CAPACITY_TPP
#define RBT_CAPACITY_TPP

#include "./RBT.hpp"

namespace ft
{
	template <RBT_TEMPLATE>
	bool RBT_CLASS::empty( void ) const
	{
		return (_size == 0);
	}
		template <RBT_TEMPLATE>
	typename RBT_CLASS::size_type RBT_CLASS::size( void ) const
	{
		return (_size);
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::size_type RBT_CLASS::max_size( void ) const
	{
		return (_alloc.max_size());
	}
}
#endif
