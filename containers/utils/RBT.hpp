/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:32:21 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/19 21:40:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include "./RBT_node.hpp"
#include "./RBT_iterator.hpp"
#include "./RBT_reverse_iterator.hpp"
#include "./equal.hpp"
#include "./lexicographicalCompare.hpp"
#include <memory>
#include <string>
#include <iostream>

#define RBT_TEMPLATE	typename Key, typename Value, typename KeyOfValue,	\
						typename Compare, typename Allocator

#define RBT_CLASS		RedBlackTree<Key, Value, KeyOfValue, Compare, Allocator>

#define CONSTRUCT 0

#define NEWNODE 1

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
			typedef ptrdiff_t															difference_type;
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
			iterator	simple_insert(value_type data);
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

			allocator_type	get_allocator( void ) const;
			const_iterator	upper_bound( const key_type &k) const;
			iterator		upper_bound( const key_type &k);
			const_iterator	lower_bound( const key_type &k) const;
			iterator		lower_bound( const key_type &k);
			key_compare		key_comp( void ) const;
			void			clear( void );
			void			swap(RedBlackTree& other);
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

	template <class K, class V, class KOV, class C, class A>
	inline bool operator==(const ft::RedBlackTree<K, V, KOV, C, A> rhs,
							const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (rhs.size() == lhs.size() && ft::equal(rhs.begin(), rhs.end(), lhs.begin()));
	}

	template <class K, class V, class KOV, class C, class A>
	inline bool operator!= (const ft::RedBlackTree<K, V, KOV, C, A> rhs,
							const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (!(rhs == lhs));
	}

	template <class K, class V, class KOV, class C, class A>
	inline bool operator<(const ft::RedBlackTree<K, V, KOV, C, A> rhs,
						const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class K, class V, class KOV, class C, class A>
	inline bool operator<=(const ft::RedBlackTree<K, V, KOV, C, A> rhs,
							const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (!(lhs < rhs));
	}

	template <class K, class V, class KOV, class C, class A>
	inline bool operator>(const ft::RedBlackTree<K, V, KOV, C, A> rhs,
							const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (lhs < rhs);
	}

	template <class K, class V, class KOV, class C, class A>
	inline bool operator>=(const ft::RedBlackTree<K, V, KOV, C, A> rhs,
							const ft::RedBlackTree<K, V, KOV, C, A> lhs)
	{
		return (!(rhs < lhs));
	}
}

#include "./RBT.tpp"
#include "./RBT_capacity.tpp"
#include "./RBT_print.tpp"
#include "./RBT_private.tpp"
#include "./RBT_iterator.tpp" // awkward rev it
#include "./RBT_modifiers.tpp"

#endif //RBT_HPP


