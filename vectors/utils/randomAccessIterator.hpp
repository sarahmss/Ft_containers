/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:26:35 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/14 00:01:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
	template<typename T>
	class random_access_iterator
	{
		public:
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef T&								reference;
			typedef random_access_iterator<T>		iterator;
			typedef random_access_iterator<const T>	const_iterator;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;
		private:
			pointer									_pointer;

		public:
			random_access_iterator( void ): _pointer(NULL){}
			random_access_iterator( pointer ptr ): _pointer(ptr){}
			random_access_iterator( const random_access_iterator& rhs ){ *this = rhs; }
			~random_access_iterator( void ){}

			random_access_iterator& operator=( const random_access_iterator& rhs)
			{
				this->_pointer = rhs._pointer;
				return *this;
			}

			operator const_iterator() const { return const_iterator(_pointer); }

			iterator& operator++( void )	// pre increment
			{
				_pointer++;
				return (*this);
			}

			iterator operator++( int )		// post increment
			{
				iterator it = *this;
				++(*this);
				return (it);
			}

			iterator& operator--( void )	// pre decrement
			{
				_pointer--;
				return (*this);
			}

			iterator operator++( int )		// post decrement
			{
				iterator it = *this;
				--(*this);
				return (it);
			}

			reference operator[]( int index )
			{
				return (*(_pointer + index))
			}

			pointer operator->( void )
			{
				return (_pointer);
			}

			reference operator*( void )
			{
				return (*(_pointer));
			}

			bool operator==( const iterator& it ) const
			{
				return (_pointer == it._pointer);
			}

			bool operator!=( const iterator& it ) const
			{
				return (_pointer != it._pointer);
			}
	}
}

#endif //RANDOM_ACCESS_ITERATOR_HPP
