/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_aux.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:01:47 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/21 14:59:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_AUX_TPP
#define RBT_AUX_TPP

#include "./RBT.hpp"

namespace ft
{
	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtLeftRotate(node_ptr x)
	{
		node_ptr y = x->right;

		x->right = y->left;
		if (y->left != TNULL)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == TNULL)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtRightRotate(node_ptr x)
	{
		node_ptr y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == TNULL)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtDestructorAux(node_ptr node)
	{
		if (node != TNULL)
		{
			RbtDestructorAux(node->left);
			RbtDestructorAux(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtFixInsert (node_ptr k)
	{
		node_ptr u;
		while (k->parent->color == RED)
		{
			if (k->parent == k->parent->parent->left)
			{
				u = k->parent->parent->right; // uncle
				if (u->color == RED) {
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						RbtLeftRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					RbtRightRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->left;
				if (u->color == RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						RbtRightRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					RbtLeftRotate(k->parent->parent);
				}
			}
		}
		root->color = BLACK;
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::iterator RBT_CLASS::RbtInsertAux(value_type data)
	{
		node_ptr z = RbtNewNode(data, RED, NEWNODE);

		node_ptr y = TNULL;
		node_ptr x = this->root;
		while (x != TNULL)
		{
			y = x;
			if (_comp(KeyOfValue()(z->data), (KeyOfValue()(x->data))))
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if (y == TNULL)
			root = z;
		else if (_comp(KeyOfValue()(z->data), (KeyOfValue()(y->data))))
			y->left = z;
		else
		{
			y->right = z;
			z->left = TNULL;
			z->right = TNULL;
			z->color = RED;
		}
		RbtFixInsert(z);
		TNULL->root = root;
		_size++;
		return (iterator(z));
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtFixErase(node_ptr x)
	{
		node_ptr s;
		while (x != root && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == RED) // case 3.1
				{
					s->color = BLACK;
					x->parent->color = RED;
					RbtLeftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == BLACK && s->right->color == BLACK) // case 3.2
				{
					s->color = RED;
					x = x->parent;
				}
				else
				{
					if (s->right->color == BLACK)
					{
						s->left->color = BLACK;
						s->color = RED;
						RbtRightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					RbtLeftRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = BLACK;
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtEraseAux(node_ptr node, value_type data)
{
		node_ptr z = TNULL;
		node_ptr x, y;
		while (node != TNULL)
		{
			if (node->data == data)
				z = node;
			if (node->data <= data)
				node = node->right;
			else
				node = node->left;
		}
		if (z == TNULL)
				throw std::invalid_argument(" [ft::RedBlackTree::Erase] Key not found");
		y = z;
		t_color y_orig_color = y->color;
		if (z->left == TNULL)
		{
			x = z->right;
			RbtTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			RbtTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_orig_color = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = y;
			else
			{
				RbtTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			RbtTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		_alloc.destroy(z);
		_alloc.deallocate(z, 1);
		if (y_orig_color == BLACK)
			RbtFixErase(x);
		TNULL->root = root;
		_size--;
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtTransplant(node_ptr u, node_ptr v)
	{
		if (u->parent == TNULL)
			root = v;
		else if ( u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	template <RBT_TEMPLATE>
	void RBT_CLASS::RbtCopy(node_ptr node)
	{
		if (node != node->leaf)
		{
			RbtInsertAux(node->data);
			RbtCopy(node->left);
			RbtCopy(node->right);
		}
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::RbtSearchTreeAux(node_ptr node, Key key) const
	{
		if (node == TNULL || (!_comp(key, KeyOfValue()(node->data))
							&& !_comp(KeyOfValue()(node->data), key)))
			return node;
		if ((_comp(key, KeyOfValue()(node->data))))
			return (RbtSearchTreeAux(node->left, key));
		return (RbtSearchTreeAux(node->right, key));
	}

	template <RBT_TEMPLATE>
	typename RBT_CLASS::node_ptr RBT_CLASS::RbtNewNode(value_type data, t_color color, int flag)
	{
		node_ptr newNode = _alloc.allocate(1);
		node n = node(data, root, TNULL, TNULL, TNULL, TNULL, color);
		if (flag == CONSTRUCT)
			n = node(data, root, newNode, newNode, newNode, newNode, color);
		_alloc.construct(newNode, n);
		return newNode;
	}
}

#endif //RBT_AUX_TPP
