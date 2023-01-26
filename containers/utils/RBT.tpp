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

	/***************************** Source functions *******************************************/
	template <RBT_TEMPLATE>
	RBT_CLASS::RedBlackTree(const key_compare& comp, const allocator_type& allocator )
	{
		_alloc = allocator;
		_size = 0;
		_comp = comp;
		root = NULL;
		TNULL = RbtNewNode(value_type(), BLACK, CONSTRUCT);
		root = TNULL;
		TNULL->root = root;
	}
	template <RBT_TEMPLATE>
	RBT_CLASS::RedBlackTree(const RedBlackTree& rhs)
	{
		_alloc = rhs._alloc;
		TNULL = RbtNewNode(value_type(), BLACK, CONSTRUCT);
		root = TNULL;
		RbtCopy(rhs.root);
		_size = rhs._size;
		_comp = rhs._comp;
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
			TNULL = RbtNewNode(value_type(), BLACK, CONSTRUCT);
			root = TNULL;
			RbtCopy(rhs.root);
		}
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::get_root( void )
	{
		return (root);
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::erase(key_type key)
	{
		node_ptr z = search(key);
		if (z == TNULL)
			return ;
		RbtEraseAux(this->root, z->data);
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::insert(value_type data)
	{
		node_ptr z = search(KeyOfValue()(data));
		if (z != TNULL)
			RbtEraseAux(this->root, z->data);
		RbtInsertAux(data);
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::insert(value_type data, node_ptr tree)
	{
		node_ptr z = search(KeyOfValue()(data), tree);
		if (z != TNULL)
			RbtEraseAux(this->root, z->data);
		RbtInsertAux(data);
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::simple_insert(value_type data, node_ptr tree) { return (RbtInsertAux(data)); }

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::search(key_type k) const
	{
		return (RbtSearchTreeAux(root, k));
	}
	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::search(key_type k, node_ptr tree) const
	{
		return (RbtSearchTreeAux(tree, k));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::minimum(node_ptr node) const
	{
		return (node->minimum(node));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::maximum(node_ptr node) const
	{
		return (node->maximum(node));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::successor(node_ptr x) const
	{
		return (x->successor(x));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::predecessor(node_ptr x) const
	{
		return (x->predecessor(x));
	}
}

#endif //RBT_TPP

