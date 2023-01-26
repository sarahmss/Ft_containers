/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:25:53 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/26 02:31:16 by coder            ###   ########.fr       */
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

#define RBT_TEMPLATE	typename Key, typename Value, typename KeyOfValue,	\
						typename Compare, typename Allocator

#define RBT_CLASS		RedBlackTree<Key, Value, KeyOfValue, Compare, Allocator>

#define CONSTRUCT 0

#define NEWNODE 1

/*
	-> A red black tree is  a binary search tree with following 5 properties:
		- Every node in T is either RED or BLACK
		- The ROOT node is BLACK
		- Every NULL node -that wich doesn't contain any keys- is black
		- If a node is red, both of its children are black
		- Every path from a ROOT node to a NULL node has the same number of black nodes
	-> Dynamic set operation:
		- Search
		- Predecessor
		- Succesor
		- insert
		- delete
	-> Insertion and deletion may violate the invariants creterials, to solve that we need to restru
		cture the tree through:
		- rotation is a transformation technique used to change the structure
		of bts without changing the order of the elements.
				a) Left rotation:
				b)  right rotation:
		- Recolor: flips the color of a node
	-> it is called balanced search because its height is always in the order of O(log n)

				  [61]
				/      \
			   /	    \
			[52]        [85]
		    /   \       /   \
		   /	 \	   /	 \
		  /		  \   /		  \
		 [20]    [55](76)     (93)
		 /  \    / \
		(16) [N][N][N]
		/  \
	[N] [N]
*/
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
			typedef ft::rbt_rev_it<iterator>											reverse_iterator;
			typedef ft::rbt_rev_it<const_iterator>										const_reverse_iterator;

		private:
			node_ptr		root;
			node_ptr		TNULL;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;

			void		RbtLeftRotate(node_ptr x);
			void		RbtRightRotate(node_ptr x);
			void		RbtDestructorAux(node_ptr node);
			void		RbtFixInsert (node_ptr k);
			iterator	RbtInsertAux(value_type data);
			void		RbtFixErase(node_ptr x);
			void		RbtEraseAux(node_ptr node, value_type data);
			void		RbtTransplant(node_ptr u, node_ptr v);
			void		RbtCopy(node_ptr node);
			node_ptr	RbtSearchTreeAux(node_ptr node, Key key) const;
			node_ptr	RbtNewNode(value_type data, t_color color, int flag);
			void		preOrderPrint(node_ptr node) const;
			void		postOrderPrint(node_ptr node) const;
			void		inOrderPrint(node_ptr node) const;;
			void		printAux(node_ptr root, std::string indent, bool last) const;

		public:
			// RbtFunctions
			explicit RedBlackTree(const key_compare& comp = key_compare(),
						const allocator_type& allocator = allocator_type());
			RedBlackTree(const RedBlackTree& rhs);
			~RedBlackTree( void );
			RedBlackTree& operator=(const RedBlackTree& rhs);
			node_ptr	get_root( void );
			void		erase(key_type key);
			void		insert(value_type data, node_ptr tree);
			void		insert(value_type data);
			node_ptr	predecessor(node_ptr x) const;
			node_ptr	successor(node_ptr x) const;
			node_ptr	maximum(node_ptr node) const;
			node_ptr	minimum(node_ptr node) const;
			node_ptr	search(key_type k, node_ptr tree) const;
			node_ptr	search(key_type k) const;
			void		prettyPrint( void ) const;
			void		preOrder( void ) const;
			void		postOrder( void ) const;
			void		inOrder( void ) const;

		/*	allocator_type	get_allocator( void ) const;
			const_iterator	upper_bound( const key_type &k) const;
			iterator		upper_bound( const key_type &k);
			const_iterator	lower_bound( const key_type &k) const;
			iterator		lower_bound( const key_type &k);
			key_compare		key_comp( void ) const;
			void			clear( void );
			void			swap(RedBlackTree& other);*/
			reverse_iterator		rbegin( void );
			const_reverse_iterator	rbegin( void ) const;
			reverse_iterator		rend( void );
			const_reverse_iterator	rend( void ) const;
			iterator				begin( void );
			const_iterator			begin( void ) const;
			iterator				end( void );
			const_iterator			end( void ) const;
			bool					empty( void ) const;
			size_type				size( void ) const;
			size_type				max_size( void ) const;

	};
}

#include "./RBT.tpp"
#include "./RBT_capacity.tpp"
#include "./RBT_print.tpp"
#include "./RBT_private.tpp"
#include "./RBT_iterator.tpp"

#endif //RBT_HPP


