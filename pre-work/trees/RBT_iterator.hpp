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

#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP

#include "RBT.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template<typename Iterator>
	class rbt_it : public std::iterator<std::bidirectional_iterator_tag, Iterator>
	{
		public:
			typedef	Iterator													iterator_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef Node<value_type>											node;
			typedef node*														node_ptr;
			typedef const node*													const_node_ptr;

		protected:
			node_ptr														_node;
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

			reference operator*( void )		// return rvalue (value where point the pointer)
			{
				return (_node->data);
			}

			pointer operator->( void ) const { return (&(operator*())); }

			rbt_it& operator++( void )								// pre increment
			{
				_node = node::sucessor(_node);
				return (*this);
			}

			rbt_it operator++( int )							// post increment
			{
				node_ptr tmp = _node;
				_node = node::sucessor(_node);
				return (rbt_it(tmp));
			}

			rbt_it& operator--( void )					// pre decrement
			{
				_node = node::predecessor(_node);
				return (*this);
			}

			rbt_it operator--( int )						// post decrement
			{
				node_ptr tmp = _node;
				_node = node::predecessor(_node);
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


#endif //RBT_ITERATOR_HPP
