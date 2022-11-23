/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/22 21:07:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "utils/randomAccessIterator.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/equal.hpp"
# include "utils/lexicographicalCompare.hpp"

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
			/*--------- Member types -------------*/
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

			/*------------ Member Functions ---------*/
			vector( void ) :	_data(NULL),
								_size(0),
								_capacity(0),
								_alloc(allocator_type())
			{
				_ReAlloc(2);
			}
			~vector( void )
			{
				this->clear();
				return ;
			}
			allocator_type get_allocator( void ) const
			{
				return this->_alloc;
			}
			vector& operator=(const vector& other)
			{
				pointer newBlock;

				_clearData();
				newBlock = _getNewBlock(other._size);
				_Construct(newBlock, other._size, value_type());
				_copyData(other._data, this->_data, other._size);
				this->_size = other._size;
				this->_alloc = other._alloc;
				return (*this);
			}
/*			void assign(size_type count, const T&value)
			{
				this->clear();
				if (count == 0)
					return;
				_ReAlloc(count);
				for (size_type i = 0; i < count; i++)
					this->_data[i] = value;
			}
			template<class InputIt>
			void assign(InputIt first, InputIt last)
			{

			}*/

									/* Modifiers */
			void push_back(const T &value)
			{
				if (_size >= _capacity)
					_ReAlloc(_capacity + (_capacity / 2));
				_data[_size] = value;
				_size++;
			}
			void pop_back( void )
			{
				this->_size -= 1;
			}
			void swap(vector &other)
			{
				pointer tempD = other._data;
				size_t	tempS = other._size;
				size_t	tempC = other._capacity;
				allocator_type tempA = other._alloc;

				other._data = this->_data;
				other._size = this->_size;
				other._capacity = this->_capacity;
				other._alloc = this->_alloc;

				this->_data = tempD;
				this->_size = tempS;
				this->_capacity = tempC;
				this->_alloc = tempA;
			}
			void clear( void ) // Erases all elements from the container
			{
				if (this->_data)
				{
					_clearData();
					this->_data = NULL;
					this->_size = 0;
				}
			}
/* 			iterator insert(const_iterator pos, const T& value) // inserts value before pos.
			{newCapacity

			} */
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

			/*-------------------- Element access --------------------------*/
			reference operator[](size_t index)
			{
				return (this->_data[index]);
			}
			const_reference operator[](size_t index) const
			{
				return (this->_data[index]);
			}
			reference at(size_type index)
			{
				if (index >= _size || index < 0)
					throw OutOfBoundsException();
				return (this->data[index]);
			}
			const_reference at(size_type index) const
			{
				if (index >= _size || index < 0)
					throw OutOfBoundsException();
				return (this->_data[index]);
			}
			reference front( void )
			{
				return (this->_data[0]);
			}
			const_reference front( void ) const
			{
				return (this->_data[0]);
			}
			reference back( void)
			{
				return (this->_data[this->_size - 1]);
			}
			const_reference back( void ) const
			{
				return (this->_data[this->_size - 1]);
			}
			pointer data( void )
			{
				return (this->_data);
			}
			const_pointer data( void ) const
			{
				return (this->_data);
			}

		private:
			/*------------------------- Utils --------------------------------*/

			void _ReAlloc(size_type newCapacity)
			{
				pointer newBlock;
				newBlock = _getNewBlock(newCapacity);
				_Construct(newBlock, newCapacity, value_type());
				_copyData (this->_data, newBlock, this->_size);
				_clearData();
				this->_data = newBlock;
				this->_capacity = newCapacity;
			}

			pointer _getNewBlock(size_t newCapacity)
			{
				pointer newBlock = _alloc.allocate(newCapacity);
				if (!newBlock)
					throw std::bad_alloc();
				return (newBlock);
			}
			void _Construct(pointer newBlock, size_type size, value_type value)
			{
				for (size_t i = 0; i < size; i++)
					_alloc.construct(newBlock + i, value);
			}
			void _copyData(pointer src, pointer dst, size_t n)
			{
				for (size_t i = 0; i < n; i++)
					dst[i] = src[i];
			}
			void _clearData()
			{
				for (size_t i = 0; i < this->_capacity; ++i)
					_alloc.destroy(this->_data + i);
				_alloc.deallocate(this->_data, this->_capacity);
			}
			/*---------------- Exceptions ------------------*/
			class OutOfBoundsException : public std::exception
			{
			public:
				char const *what() const throw()
				{
					return ("\u001b[31m Out of bounds exception \u001b[0m");
				}
			};
		};
		/*---------------- Non member functions ----------------*/

		template<class T, class Alloc>
		void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
		{
			lhs.swap(rhs);
		}
		template<class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs.size()!= rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), rhs.begin(), rhs.end()));
		}
		template<class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(lhs==rhs));
		}
		template<class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T,Alloc> &rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		template<class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}
		template<class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T,Alloc> &rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		template<class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

}

#endif // VECTOR_HPP
