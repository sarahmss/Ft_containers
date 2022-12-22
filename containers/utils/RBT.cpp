/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:47:54 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/13 21:10:49 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_TPP
#define RBT_TPP

#include "RBT.hpp"

namespace ft {

	// member functions
	template <RBT_TEMPLATE>
	RBT_CLASS::RedBlackTree(const key_compare& comp, const allocator_type& allocator )
	{
		_alloc = allocator;
		_size = 0;
		_comp = comp;
		TNULL = RbtNewNode(value_type(), BLACK);
		root = TNULL;
	}
	template <RBT_TEMPLATE>
	RBT_CLASS::RedBlackTree(const RedBlackTree& rhs)
	{
		_alloc = rhs._alloc;
		_size = rhs._size;
		_comp = rhs._comp;
		TNULL = RbtNewNode(value_type(), BLACK);
		RbtCopy(rhs.root);
		root = TNULL;
	}
	template <RBT_TEMPLATE>
	RBT_CLASS::~RedBlackTree( void )
	{
		RbtDestructorAux(root);
		_alloc.destroy(TNULL);
		_alloc.deallocate(TNULL, 1);
		_size = 0;
	}
	template <RBT_TEMPLATE>
	RBT_CLASS& RBT_CLASS::operator=(const RedBlackTree& rhs)
	{
		if (this != &rhs)
		{
			_alloc = rhs._alloc;
			_size = rhs._size;
			_comp = rhs._comp;
			TNULL = RbtNewNode(value_type(), BLACK);
			root = TNULL;
			RbtCopy(rhs.root);
		}
	}

	// Iterators
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
		return (reverse_iterator(end()));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::const_reverse_iterator RBT_CLASS::rbegin( void ) const
	{
		return (const_reverse_iterator(end()));
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

	// Capacity
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

	// modifiers
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
		root = TNUlL;
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
		returns (_alloc)
	}

	// RbtFunctions

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::search(key_type k) const
	{
		return (RbtSearchAux(root, k));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::search(key_type k, node_ptr tree) const
	{
		return (RbtSearchAux(_root, k));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::minimum(node_ptr node) const
	{
		return (rbt_node::minimum(node));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::maximum(node_ptr node) const
	{
		return (rbt_node::maximum(node));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::successor(node_ptr x) const
	{
		return (rbt_node::successor(x));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::predecessor(node_ptr x) const
	{
		return (rbt_node::predecessor(x));
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::insert(value_type data)
	{
		node_ptr z = search(KeyOfValue()(data));
		if (z != TNULL)
			RbtEraseAux(z);
		RbtInsertAux(data);
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::insert(value_type data, node_ptr tree)
	{
		node_ptr z = search(KeyOfValue()(data), tree);
		if (z != TNULL)
			RbtEraseAux(z);
		RbtInsertAux(data);
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::erase(key_type key)
	{
		node_ptr z = search(key);
		if (z == TNULL)
			return ;
		RbtEraseAux(z);
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::get_root( void )
	{
		return (root);
	}

}

#endif //RBT_TPP

