/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:25:53 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 17:50:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <cstddef>

namespace ft
{
	typedef enum e_color
	{
		BLACK,
		RED
	}			t_color;

	template <typename T>
	struct Node
	{
		typedef T						data_type;
		typedef Node<T>					node;
		typedef node*					node_ptr;
		typedef const node*				const_node_ptr;

		data_type			data;
		node_ptr			root;
		node_ptr			leaf;
		node_ptr			parent;
		node_ptr			left;
		node_ptr			right;
		t_color				color;

		explicit Node(const data_type& Data, node_ptr Root, node_ptr Leaf, node_ptr Parent = NULL,
						node_ptr Left = NULL, node_ptr Right = NULL, t_color Color = BLACK):
						data(Data), root(Root), leaf(Leaf), parent(Parent),
						left(Left), right(Right), color(Color) {}

		node_ptr minimum(node_ptr node)	// find the node with the minimum key
		 {
			while (node->left != node->leaf)
				node = node->left;
			return node;
		}
		node_ptr maximum(node_ptr node)	// find the node with the maximum key
		{
			while (node->right != node->leaf)
				node = node->right;
			return node;
		}

		node_ptr successor(node_ptr x)	// left most element in right_subtree
		{
			if (x == x->leaf)
				return (maximum(getRoot(x)));
			if (x->right != x->leaf)
				return minimum(x->right);
			node_ptr y = x->parent;
			while (y != x->leaf && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		node_ptr predecessor(node_ptr x)	// right most element in left_subtree
		{
			if (x == x->leaf)
				return (maximum(getRoot(x)));
			if (x->left != x->leaf)
				return maximum(x->left);
			node_ptr y = x->parent;
			while (y != x->leaf && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
		node_ptr getRoot( void ) { return (this->root); }
		node_ptr getRoot( node_ptr x ) { return (x->root); }

	};
}
#endif /**** TREE_NODE_HPP *****/
