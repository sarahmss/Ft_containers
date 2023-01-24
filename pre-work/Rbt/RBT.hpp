/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:27:30 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/24 20:50:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include "./RBT_node.hpp"
#include "./RBT_iterator.hpp"
#include "./RBT_reverse_iterator.hpp"
#include <memory>
#include <string>
#include <iostream>

namespace ft
{
	template	<typename Key,
				typename Value,
				typename KeyOfValue,
				typename Compare,
				typename Allocator = std::allocator<Value> >
	class RedBlackTree
	{
		typedef typename Allocator::template rebind<Node<Value> >::other				node_allocator;

		public:
			typedef node_allocator														allocator_type;
			typedef Node<Value>															node;
			typedef	node*																node_ptr;
			typedef const node*															const_node_ptr;
			typedef Compare																key_compare;
			typedef Key																	key_type;
			typedef Value																value_type;
			typedef value_type*															pointer;
			typedef const value_type*													const_pointer;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;
			typedef size_t																size_type;
			typedef ptrdiff_t															diferrence_type;
			typedef ft::rbt_it<pointer>													iterator;
			typedef ft::rbt_it<const_pointer>											const_iterator;
			typedef ft::rbt_rev_it<pointer>												reverse_iterator;
			typedef ft::rbt_rev_it<const_pointer>										const_reverse_iterator;

		private:
			node_ptr		root;
			node_ptr		TNULL;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;

		public:
	/***************************** Source functions *******************************************/
		explicit	RedBlackTree(const key_compare& comp = key_compare(),
						const allocator_type& allocator = allocator_type())
		{
			_alloc = allocator;
			_size = 0;
			_comp = comp;
			TNULL = RbtNewNode(value_type(), BLACK);
			root = TNULL;
			std::cout << "Tree constructor called" << std::endl;
		}
					RedBlackTree(const RedBlackTree& rhs)
		{
			_alloc = rhs._alloc;
			TNULL = RbtNewNode(value_type(), BLACK);
			root = TNULL;
			RbtCopy(rhs.root);
			_size = rhs._size;
			_comp = rhs._comp;
			std::cout << "Tree copy constructor called" << std::endl;
		}
					~RedBlackTree( void )
		{
			RbtDestructorAux(root);
			_alloc.destroy(TNULL);
			_alloc.deallocate(TNULL, 1);
			_size = 0;
			std::cout << "Tree destructor called" << std::endl;
		}
		node_ptr	get_root( void ) { return (root); }
		void		insert(value_type data)
		{
			node_ptr z = search(KeyOfValue()(data));
			if (z != TNULL)
				RbtEraseAux(this->root, z->data);
			RbtInsertAux(data);
		}
		void		insert(value_type data, node_ptr tree)
	{
		node_ptr z = search(KeyOfValue()(data), tree);
		if (z != TNULL)
			RbtEraseAux(this->root, z->data);
		RbtInsertAux(data);
	}
		node_ptr	search(key_type k, node_ptr tree) const
		{
			return (RbtSearchTreeAux(tree, k));
		}
		node_ptr	search(key_type k) const
		{
			return (RbtSearchTreeAux(root, k));
		}
	/***************************** Print functions *******************************************/
		void	preOrder( void ) const { preOrderPrint(this->root); }
		void	postOrder( void ) const { postOrderPrint(this->root); }
		void	inOrder( void ) const { inOrderPrint(this->root); }
		void	prettyPrint( void ) const
		{
			if (root)
				printAux(root, "", true);
		}

	private:
	/************************ Auxiliar functions *******************************************/
		void		preOrderPrint(node_ptr node) const
		{
			if (node != TNULL)
			{
				std::cout << KeyOfValue()(node->data) << " ";
				preOrderPrint(node->left);
				preOrderPrint(node->right);
			}
		}
		void		inOrderPrint(node_ptr node) const
		{
			if (node != TNULL)
			{
				postOrderPrint(node->left);
				std::cout << KeyOfValue()(node->data) << " ";
				postOrderPrint(node->right);
			}
		}
		void		postOrderPrint(node_ptr node) const
		{
			if (node != TNULL)
			{
				postOrderPrint(node->left);
				postOrderPrint(node->right);
				std::cout << KeyOfValue()(node->data) << " ";
			}
		}
		void		printAux(node_ptr root, std::string indent, bool last) const
		{
			if (root != NULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "     ";
				}
				else
				{
					std::cout << "L----";
					indent += "|     ";
				}
				std::cout << KeyOfValue()(root->data) << std::endl;
				printAux(root->left, indent, false);
				printAux(root->right, indent, true);
			}
		}
		void		RbtDestructorAux(node_ptr node)
		{
			if (node != TNULL)
			{
				RbtDestructorAux(node->left);
				RbtDestructorAux(node->right);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}
		}
		node_ptr	RbtNewNode(value_type data, t_color color)
		{
			node_ptr	newNode = _alloc.allocate(1);
			node		n = node(data, root, newNode, newNode, newNode, newNode, color);
			_alloc.construct(newNode, n);
			return newNode;
		}
		node_ptr	RbtSearchTreeAux(node_ptr node, Key key) const
		{
			if (node == TNULL || (!_comp(key, KeyOfValue()(node->data))
								&& !_comp(KeyOfValue()(node->data), key)))
				return node;
			if ((_comp(key, KeyOfValue()(node->data))))
				return (RbtSearchTreeAux(node->left, key));
			return (RbtSearchTreeAux(node->right, key));
		}
		void 		RbtCopy(node_ptr node)
		{
			if (node != node->leaf)
			{
				RbtInsertAux(node->data);
				RbtCopy(node->left);
				RbtCopy(node->right);
			}
		}
		void		RbtLeftRotate(node_ptr x)
		{
			node_ptr y = x->right;

			x->right = y->left;
			if (y->left != x->leaf)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void 		RbtRightRotate(node_ptr x)
		{
			node_ptr y = x->left;
			x->left = y->right;
			if (y->right != x->leaf)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		void		RbtFixInsert (node_ptr k)
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
		iterator	RbtInsertAux(value_type data)
		{
			node_ptr z = RbtNewNode(data, RED);

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
		void		RbtFixErase(node_ptr x)
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
		void		RbtEraseAux(node_ptr node, value_type data)
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
		void		RbtTransplant(node_ptr u, node_ptr v)
	{
		if (u->parent == TNULL)
			root = v;
		else if ( u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}
		node_ptr	minimum(node_ptr node) const
		{
			return (node->minimum(node));
		}
		node_ptr	maximum(node_ptr node) const
		{
			return (node::maximum(node));
		}
	};
}

#endif
