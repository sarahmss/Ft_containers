/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_rev_it.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:20 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/12 21:07:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_REVERSE_ITERATOR_HPP
#define RED_BLACK_TREE_REVERSE_ITERATOR_HPP


#include "red_black_tree.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template<typename It>
	class rbt_rev_it : public iterator<std::bidirectionla_iterator_tag, It>
	{public iterator <typename iterator_traits<It>::iterator_category,
									typename iterator_traits<It>::value_type,
									typename iterator_traits<It>::difference_type,
									typename iterator_traits<It>::pointer,
									typename iterator_traits<It>::reference>
	{
		public:
			typedef	It															iterator_type;
			typedef typename iterator_traits<It>::value_type					value_type;
			typedef typename iterator_traits<It>::difference_type				difference_type;
			typedef typename iterator_traits<It>::pointer						pointer;
			typedef typename iterator_traits<It>::reference						reference;
			typedef typename iterator_traits<It>::iterator_category				iterator_category;
			typedef Node<value_type>											node;
			typedef node*														node_ptr;
			typedef const node*													const_node_ptr;

		protected:
			node_ptr														_node;
		public:
			rbt_rev_it( void ): _node(NULL){}
			rbt_rev_it( pointer ptr ): _node(ptr){}
			rbt_rev_it( iterator_type x ){ node = x.base() }
			rbt_rev_it( const rbt_rev_it& rhs ){ node = x.node}
			~rbt_rev_it( void ){}

			const pointer base() const { return _node; }

			rbt_rev_it& operator=( const rbt_rev_it& rhs) // assignment operator
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			}

			reference operator*( void )	const											// return rvalue (value where point the pointer)
			{
				node_ptr tmp = Node::sucessor(_node);
				return (tmp->data);
			}

			pointer operator->( void ) const { return (&(operator*())); }

			rbt_rev_it& operator++( void )								// pre increment
			{
				_node = node::predecessor(_node);
				return (*this);
			}

			rbt_rev_it operator++( int )							// post increment
			{
				node_ptr tmp = _node;
				_node = node::predecessor(_node);
				return (rbt_rev_it(tmp));
			}

			rbt_rev_it& operator--( void )					// pre decrement
			{
				_node = node::sucessor(_node);
				return (*this);
			}

			rbt_rev_it operator--( int )						// post decrement
			{
				node_ptr tmp = _node;
				_node = node::sucessor(_node);
				return (rbt_rev_it(tmp));
			}
	};

	template<class It>
	bool operator==(const ft::rbt_rev_it<It>& lhs, const ft::rbt_rev_it<It>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class It>
	bool operator!=(const ft::rbt_rev_it<It>& lhs, const ft::rbt_rev_it<It>& rhs){
		return lhs.base() != rhs.base();
	}

		template<class ItL, class ItR>
	bool operator==(const ft::rbt_rev_it<ItL>& lhs, const ft::rbt_rev_it<ItR>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class ItL, class ItR>
	bool operator!=(const ft::rbt_rev_it<ItL>& lhs, const ft::rbt_rev_it<ItR>& rhs){
		return lhs.base() != rhs.base();
	}
}



#endif //#ifndef RED_BLACK_TREE_REVERSE_ITERATOR_HPP

