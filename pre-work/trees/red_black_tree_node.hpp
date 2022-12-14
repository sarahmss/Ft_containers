/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_node.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:25:53 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/13 21:00:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

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
		typedef Node<data_type>			node;
		typedef node*					node_ptr;
		typedef const node*				const_node_ptr;

		data_type			data;
		node_ptr			root;
		node_ptr			leaf;
		node_ptr			parent;
		node_ptr			left;
		node_ptr			right;
		t_color				color;

		explicit Node(const data_type& Data,
						node_ptr Root,
						node_ptr Leaf,
						node_ptr Parent = NULL,
						node_ptr Left = NULL,
						node_ptr Right = NULL,
						node_ptr Color = BLACK):
						data(Data),
						root(Root),
						leaf(Leaf),
						parent(Parent),
						left(Left),
						right(Right),
						color(Color) {}


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
		/*
			find the successor of a given node
				left most element in right_subtree
		*/
		node_ptr successor(node_ptr x)
		{
			if (x == x->leaf)
				return (maximum(get_root(x)));
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
		/*
			find the predecessor of a given node
				right most element in left_subtree
		*/
		node_ptr predecessor(node_ptr x)
		{
			if (x == x->leaf)
				return (maximum(get_root(x)));
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
	};
}
#endif /**** TREE_NODE_HPP *****/
