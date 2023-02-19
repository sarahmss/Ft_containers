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

#ifndef RBT_REVERSE_ITERATOR_HPP
#define RBT_REVERSE_ITERATOR_HPP


#include "RBT.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template<typename Iterator>
	class rbt_rev_it : public std::iterator <typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
		{
			public:
				typedef	Iterator													iterator_type;
				typedef typename iterator_traits<iterator_type>::value_type			value_type;
				typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
				typedef typename iterator_traits<iterator_type>::pointer			pointer;
				typedef typename iterator_traits<iterator_type>::reference			reference;
				typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
				typedef Node<value_type>											node;
				typedef node*														node_ptr;
				typedef const node*													const_node_ptr;

			protected:
				node_ptr														_node;
			public:
				rbt_rev_it( void ): _node(NULL){}

				explicit rbt_rev_it( iterator_type it ): _node(it.base()) {}

				explicit rbt_rev_it( node_ptr ptr ): _node(ptr){}

				rbt_rev_it( const rbt_rev_it& rhs ): _node(rhs._node){ }

				template <typename It>
				rbt_rev_it( const rbt_rev_it<It> & x): _node(x.base()) {}

				~rbt_rev_it( void ){}

				node_ptr base() const { return _node; }

				rbt_rev_it& operator=( const rbt_rev_it& rhs) // assignment operator
				{
					if (this == &rhs)
						return (*this);
					this->_node = rhs._node;
					return (*this);
				}

				reference operator*( void )	const // return rvalue (value where point the pointer)
				{
					node_ptr tmp = _node->predecessor(_node);
					return (tmp->data);
				}

				pointer operator->( void ) const { return (&(this->operator*())); }

				rbt_rev_it& operator++( void )								// pre increment
				{
					_node = _node->predecessor(_node);
					return (*this);
				}

				rbt_rev_it operator++( int )							// post increment
				{
					node_ptr tmp = _node;
					_node = _node->predecessor(_node);
					return (rbt_rev_it(tmp));
				}

				rbt_rev_it& operator--( void )					// pre decrement
				{
					_node = _node->successor(_node);
					return (*this);
				}

				rbt_rev_it operator--( int )						// post decrement
				{
					node_ptr tmp = _node;
					_node = _node->successor(_node);
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



#endif //#ifndef RBT_REVERSE_ITERATOR_HPP

