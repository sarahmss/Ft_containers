/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/13 17:32:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

/*
	-> Reimplementation of vector container

	-> Private attributes:
		- _data;		Pointer for whatever T it is
		- _size;		Number of elments
		- _alloc;	How much could we store without realocating
	Since memory must be contiguos _alloc is fundamental to keep track
			of how much memory we have before reallocating

	ReAlloc --> Growing function which makes realocation more efficient
				1. Allocate a new block of memory
				2. copy/move old elements into new block
				3. delete[] expression;
*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		private:
			T		*_data;
			size_t	_size;
			size_t	_alloc;

		public:

			vector(void) :	_data(NULL),
							_size(0),
							_alloc(0)
			{
				ReAlloc(2);
			}

			void push_back(const T &value)
			{
				if (_size >= _alloc)
					ReAlloc(_alloc + (_alloc / 2));
				_data[_size] = value;
				_size++;
			}

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

			size_t size(void) const
			{
				return (_size);
			}

		private:
			void ReAlloc(size_t newCapacity)
			{
				T *newBlock = new T[newCapacity];

				if (newCapacity < _size)
					_size = newCapacity;

				for (size_t i = 0; i < _size; i++)
				{
					newBlock[i] = _data[i];
				}
				delete[] _data;
				_data = newBlock;
				_alloc = newCapacity;
			}
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
