/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_modifiers.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:28:40 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/16 14:37:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RBT_MODIFIERS_TPP
#define RBT_MODIFIERS_TPP

#include "RBT.hpp"

namespace ft {
	template <RBT_TEMPLATE>
	void RBT_CLASS::swap(RedBlackTree& other)
	{
		allocator_type tmpAlloc = other._alloc;
		node_ptr tmpRoot = other.root;
		node_ptr tmpTNULL = other.TNULL;
		size_type tmpSize = other._size;
		key_compare tmpComp = other._comp;

		other._alloc = this->_alloc;
		other._size = this->_size;
		other.root = this->_root;
		other.TNULL = this->_TNULL;
		other._comp = this->_comp;

		this->_alloc = tmpAlloc;
		this->root = tmpRoot;
		this->_size = tmpSize;
		this->_comp = tmpComp;
		this->TNULL = tmpTNULL;
	}
	template<RBT_TEMPLATE>
	void RBT_CLASS::clear( void )
	{
		RbtDestructorAux(root);
		root = TNULL;
		_size = 0;
	}
	template<RBT_TEMPLATE>
	typename RBT_CLASS::key_compare RBT_CLASS::key_comp( void ) const
	{
		return (_comp);
	}
	template<RBT_TEMPLATE>
	typename RBT_CLASS::iterator RBT_CLASS::lower_bound( const key_type &k)
	{
		node_ptr x = root;
		node_ptr y = TNULL;
		while(x != TNULL)
		{
			if (!_comp(KeyOfValue()(x->data), k))
			{
				y = x;
				x = x->left;
			}
			else
				x = x->right;
		}
		return (iterator(y));
	}
	template<RBT_TEMPLATE>
	typename RBT_CLASS:: const_iterator RBT_CLASS::lower_bound( const key_type &k) const
	{
		node_ptr x = root;
		node_ptr y = TNULL;
		while(x != TNULL)
		{
			if (!_comp(KeyOfValue()(x->data), k))
			{
				y = x;
				x = x->left;
			}
			else
				x = x->right;
		}
		return (iterator(y));
	}
	template<RBT_TEMPLATE>
	typename RBT_CLASS::iterator RBT_CLASS::upper_bound( const key_type &k)
	{
		node_ptr x = root;
		node_ptr y = TNULL;
		while(x != TNULL)
		{
			if (!_comp(k, KeyOfValue()(x->data)))
			{
				y = x;
				x = x->left;
			}
			else
				x = x->right;
		}
		return (iterator(y));
	}
	template<RBT_TEMPLATE>
	typename RBT_CLASS::const_iterator RBT_CLASS::upper_bound( const key_type &k) const
	{
		node_ptr x = root;
		node_ptr y = TNULL;
		while(x != TNULL)
		{
			if (!_comp(k, KeyOfValue()(x->data)))
			{
				y = x;
				x = x->left;
			}
			else
				x = x->right;
		}
		return (iterator(y));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::allocator_type RBT_CLASS::get_allocator( void ) const
	{
		return (_alloc);
	}
}
#endif
