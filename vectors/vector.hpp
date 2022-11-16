/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/16 00:57:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "utils/randomAccessIterator.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/reverseIterator.hpp"

/*
	-> Reimplementation of vector container
	-> Private attributes:
		- _data;		Pointer for whatever T it is
		- _size;		Number of elments
		- _capacity;		How much could we store without realocating
	Since memory must be contiguos _capacity is fundamental to keep track
			of how much memory we have before _reallocating

	_ReAlloc --> Growing function which makes realocation more efficient
				1. Allocate a new block of memory
				2. copy/move old elements into new block
				3. delete[] expression;
*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			/*---------------------------Member types--------------------------------------------*/
			typedef	T															value_type;
			typedef	Alloc														allocator_type;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::random_access_iterator<value_type>						iterator;
			typedef ft::random_access_iterator<const value_type>				const_iterator;
 			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

		private:
			T				*_data;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

		public:

			/*-------------------- Member Functions --------------------------*/
			vector( void ) :	_data(NULL),
							_size(0),
							_capacity(0)
			{
				_ReAlloc(2);
			}
			~vector( void )
			{
				for (size_t i = 0; i < this->_capacity; ++i)
					_alloc.destroy(this->_data + i);
				if (this->_data)
					_alloc.deallocate(this->_data, this->_capacity);
				return ;
			}

									/* Modifiers */
			void push_back(const T &value)
			{
				if (_size >= _capacity)
					_ReAlloc(_capacity + (_capacity / 2));
				_data[_size] = value;
				_size++;
			}

									/* Capacity */
			size_type	size( void ) const
			{
				return (_size);
			}
			size_type	capacity() const
			{
				return (_capacity);
			}
			bool		empty( void ) const
			{
				return (_size == 0 ? true : false);
			}
			size_type	max_size( void ) const
			{
				return (_alloc.max_size());
			}
			void		reserve( size_type new_cap )
			{
				size_type oldCapacity = this->_capacity;
				if (new_cap <= _capacity)
					return ;
				if (new_cap > this->max_size())
					throw OutOfBoundsException();
				_ReAlloc(new_cap);
			}
									/* Iterators */
			iterator begin( void )
			{
				return (iterator(this->_data));
			}
			iterator end( void )
			{
				return (iterator(this->_data + this->_size));
			}
			const_iterator begin( void ) const
			{
				return (const_iterator(this->_data));
			}
			const_iterator end( void ) const
			{
				return (const_iterator(this->_data + this->_size));
			}
			reverse_iterator rbegin( void )
			{
				return (reverse_iterator(this->end() - 1));
			}
			const_reverse_iterator rbegin( void ) const
			{
				return (const_reverse_iterator(this->end() - 1));
			}
			reverse_iterator rend( void )
			{
				return(reverse_iterator(this->begin() - 1));
			}
			const_reverse_iterator rend( void ) const
			{
				return(const_reverse_iterator(this->begin() - 1));
			}

			/*-------------------- Operators --------------------------*/
			T &operator[](size_t index)
			{
				if (index >= _size || index < 0)
					throw OutOfBoundsException();
				return (_data[index]);
			}

			const T &operator[](size_t index) const
			{
				if (index >= _size || index < 0)
					throw OutOfBoundsException();
				return (_data[index]);
			}

		private:
			/*------------------------- Utils --------------------------------*/
			void _ReAlloc(size_t newCapacity)
			{
				pointer newBlock = _alloc.allocate(newCapacity + 1);

				if (!newBlock)
					throw std::bad_alloc();
				if (newCapacity < _size)
					_size = newCapacity;
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(newBlock + i, value_type());
				for (size_t i = 0; i < this->_capacity; ++i)
					_alloc.destroy(this->_data + i);
				_alloc.deallocate(this->_data, this->_capacity);
				_data = newBlock;
				_capacity = newCapacity;
			}
			/*------------------------- Exceptions ---------------------------*/
			class OutOfBoundsException : public std::exception
			{
			public:
				char const *what() const throw()
				{
					return ("\u001b[31m Out of bounds exception \u001b[0m");
				}
			};
		};
}

#endif // VECTOR_HPP
