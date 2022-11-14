/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:26:35 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/13 23:16:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>

namespace ft
{
	template<typename T>
	class iterators
	{
		public:
			typedef	T						value_type;
			typedef	value_type*				pointer;
			typedef typename value_type&	reference;

		private:
			pointer							_mPtr;

		public:
			iterator( pointer ptr ): _mPtr(ptr)
			{
				return ;
			}

			iterator& operator++( void )	// pre increment
			{
				_mPtr++;
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
				_mPtr--;
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
				return (*(_mPtr + index))
			}

			pointer operator->( void )
			{
				return (_mPtr);
			}

			reference operator*( void )
			{
				return (*(_mPtr));
			}

			bool operator==( const iterator& it ) const
			{
				return (_mPtr == it._mPtr);
			}

			bool operator!=( const iterator& it ) const
			{
				return (_mPtr != it._mPtr);
			}
	}
}
