/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:17:29 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/13 17:12:43 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft
{
	template <class Iter >
	class reverse_iterator
	{
		public:
			typedef Iter													iterator_type;
			typedef typename iterator_traits<Iter>::value_type				value_type;
			typedef typename iterator_traits<Iter>::iterator_category		iterator_category;
			typedef typename iterator_traits<Iter>::difference_type			difference_type;
			typedef typename iterator_traits<Iter>::pointer					pointer;
			typedef typename iterator_traits<Iter>::reference				reference;
		protected:
			iterator_type	_current;
		public:
			reverse_iterator( void ): _current(){}
			explicit reverse_iterator( iterator_type it ): _current(it){} // construct a reverse_iterator object from an original iterator it
			reverse_iterator( const reverse_iterator<Iter>& other ): _current(other._current){ }
			template <class It>
			reverse_iterator(const reverse_iterator<It>& other ): _current(other.base()){} // construct a reverse_iterator object from other reverse_iterator
			virtual ~reverse_iterator( void ){}

			iterator_type base() const { return _current; } // return a copy of the base iterator

			reference operator[]( int index )				// a reference to the element placed at index
			{
				return (this->base()[index - 1]);
			}

			pointer operator->( void )						// return lvalue (pointer to the element)
			{
				return &(operator*());
			}

			reference operator*( void )						// return a reference to the element pointed by it
			{
				iterator_type temp = this->_current;
				return (*(temp));
			}

			reverse_iterator operator+( difference_type n ) const	// a iterator where the element is pointed at this - n in memory
			{
				return (reverse_iterator(base() - n));
			}

			reverse_iterator operator-( difference_type n ) const	// a iterator where the element is pointed at this + n in memory
			{
				return (reverse_iterator(base() + n));
			}

			reverse_iterator& operator++( void )					// pre increment
			{
				this->_current--;
				return (*this);
			}

			reverse_iterator operator++( int )						// post increment
			{
				reverse_iterator it = *this;
				this->_current--;
				return (it);
			}

			reverse_iterator& operator--( void )					// pre decrement
			{
				this->_current++;
				return (*this);
			}

			reverse_iterator operator--( int )						// post decrement
			{
				reverse_iterator it = *this;
				++(*this);
				return (it);
			}

			reverse_iterator operator+=( difference_type n ) const	// a reference to the element placed at the actual pointer memory - n
			{
				_current -= n;
				return (*this);
			}

			reverse_iterator operator-=( difference_type n ) const	// a reference to the element placed at the actual pointer memory + n
			{
				_current += n;
				return (*this);
			}
	};

	template<class Iter>
	bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class Iter>
	bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return lhs.base() != rhs.base();
	}

	template<class Iter>
	bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return lhs.base() < rhs.base();
	}

	template<class Iter>
	bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return lhs.base() <= rhs.base();
	}

	template<class Iter>
	bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return lhs.base() > rhs.base();
	}

	template<class Iter>
	bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return lhs.base() >= rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator==(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() == rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator!=(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() != rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator<(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() < rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator<=(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() <= rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator>(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() > rhs.base();
	}

	template<class Iter_L, class Iter_R>
	bool operator>=(const ft::reverse_iterator<Iter_L>& lhs, const ft::reverse_iterator<Iter_L>& rhs){
		return lhs.base() >= rhs.base();
	}

	template<class Iter>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
	{
		return (it.base() - n);
	}

	template< class Iter >
	typename reverse_iterator<Iter>::difference_type operator-( const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

}


#endif //REVERSE_ITERATOR_HPP


