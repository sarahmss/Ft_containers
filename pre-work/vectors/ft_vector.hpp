/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/10 05:11:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include "ft_allocator.hpp"

/*
	Since memory must be contiguos m_capacity is fundamental to keep track
			of how much memory we have before reallocating

	ReAlloc --> Growing function which makes realocation more efficient 
				1. Allocate a new block of memory
				2. copy/move old elements into new block
				3. delete[] expression;

*/

template <typename T, typename Allocator = ft_allocator<T> >
class ft_vector
{
	public: 
		ft_vector( void )
		{
			ReAlloc(2);
		}
		void	PushBack (const T& value)
		{
			if (this->m_Size >= this->m_Capacity)
				ReAlloc(this->m_Capacity + (this->m_Capacity / 2));
			this->m_Data[this->m_Size] = value;
			this->m_Size++;
		}
		
		T& operator[](size_t index)
		{
			if ( index >= this->m_Size || index < 0)
				throw OutOfBoundsException(); 		
			return (this->m_Data[index]); 
		}
		const T& operator[](size_t index) const
		{
			if ( index >= this->m_Size || index < 0)
				throw OutOfBoundsException(); 
			return (this->m_Data[index]); 
		}
	
		size_t getSize( void ) const { return this->m_Size; }
	private:
		void	ReAlloc(size_t newCapacity)
		{
			Allocator<T> allocator;
			
			T	*newBlock = allocator.allocate(newCapacity);

			if (newCapacity < this->m_Size)
				this->m_Size = newCapacity;
			
			for (size_t i = 0; i < this->m_Size; i++)
			{
				newBlock[i] = this->m_Data[i]; 
			}	
			allocator.deallocate(this->m_Data);
			this->m_Data = newBlock;
			this->m_Capacity = newCapacity;
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

#endif //FT_VECTOR_HPP
