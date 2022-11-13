/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/13 15:54:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

/*
	Since memory must be contiguos m_capacity is fundamental to keep track
			of how much memory we have before reallocating

	ReAlloc --> Growing function which makes realocation more efficient
				1. Allocate a new block of memory
				2. copy/move old elements into new block
				3. delete[] expression;

*/

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			vector( void ) : m_Data(NULL), m_Size(0), m_Capacity(0)
			{
				ReAlloc(2);
			}
			void	push_back (const T& value)
			{
				if (m_Size >= m_Capacity)
					ReAlloc(m_Capacity + (m_Capacity / 2));
				m_Data[m_Size] = value;
				m_Size++;
			}

			T& operator[](size_t index)
			{
				if ( index >= m_Size || index < 0)
					throw OutOfBoundsException();
				return (m_Data[index]);
			}
			const T& operator[](size_t index) const
			{
				if ( index >= m_Size || index < 0)
					throw OutOfBoundsException();
				return (m_Data[index]);
			}

			size_t getSize( void ) const { return m_Size; }

		private:
			void	ReAlloc(size_t newCapacity)
			{
				T	*newBlock = new T[newCapacity];

				if (newCapacity < m_Size)
					m_Size = newCapacity;

				for (size_t i = 0; i < m_Size; i++)
				{
					newBlock[i] = m_Data[i];
				}
				delete [] m_Data;
				m_Data = newBlock;
				m_Capacity = newCapacity;
			}

			T		*m_Data;		// pointer for whatever T it is
			size_t	m_Size;			// Number of elments
			size_t	m_Capacity; 	// How much could we store without realocating

			class OutOfBoundsException : public std::exception
			{
				public:
					char const* what() const throw(){ return (" Out of bounds "); }
			};
	};
}


#endif //VECTOR_HPP
