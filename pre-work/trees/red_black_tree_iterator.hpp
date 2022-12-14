/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_it.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:20 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/12 21:07:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR_HPP
#define RED_BLACK_TREE_ITERATOR_HPP

#include "red_black_tree.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template<typename It>
	class rbt_it : public iterator<std::bidirectionla_iterator_tag, It>
	{
		public:
			typedef	It															iterator_type;
			typedef typename iterator_traits<It>::value_type					value_type;
			typedef typename iterator_traits<It>::difference_type				difference_type;
			typedef typename iterator_traits<It>::pointer						pointer;
			typedef typename iterator_traits<It>::reference						reference;
			typedef Node<value_type>											rbt_node;
			typedef rbt_node*													rbt_node_ptr;
			typedef const rbt_node*												const_rbt_node_ptr;

		protected:
			rbt_node_ptr														_node;
		public:
			rbt_it( void ): _node(NULL){}
			rbt_it( pointer ptr ): _node(ptr){}
			rbt_it( const rbt_it& rhs ){ *this = rhs; }
			~rbt_it( void ){}

			pointer base() const { return _node; }

			rbt_it& operator=( const rbt_it& rhs) // assignment operator
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			}

			reference operator*( void )												// return rvalue (value where point the pointer)
			{
				return (_node->data);
			}

			pointer operator->( void ) const { return (&(operator*())); }

			rbt_it& operator++( void )								// pre increment
			{
				_node = rbt_node::sucessor(_node);
				return (*this);
			}

			rbt_it operator++( int )							// post increment
			{
				node_ptr tmp = _node;
				_node = rbt_node::sucessor(_node);
				return (rbt_it(tmp));
			}

			rbt_it& operator--( void )					// pre decrement
			{
				_node = rbt_node::predecessor(_node);
				return (*this);
			}

			rbt_it operator--( int )						// post decrement
			{
				node_ptr tmp = _node;
				_node = rbt_node::predecessor(_node);
				return (rbt_it(tmp));
			}
	};

	template<class It>
	bool operator==(const ft::rbt_it<It>& lhs, const ft::rbt_it<It>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class It>
	bool operator!=(const ft::rbt_it<It>& lhs, const ft::rbt_it<It>& rhs){
		return lhs.base() != rhs.base();
	}

		template<class ItL, class ItR>
	bool operator==(const ft::rbt_it<ItL>& lhs, const ft::rbt_it<ItR>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class ItL, class ItR>
	bool operator!=(const ft::rbt_it<ItL>& lhs, const ft::rbt_it<ItR>& rhs){
		return lhs.base() != rhs.base();
	}
}


#endif //RED_BLACK_TREE_ITERATOR_HPP
