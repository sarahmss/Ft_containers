/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:26:35 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/14 20:14:08 by smodesto         ###   ########.fr       */
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
			typedef std::ptrdiff_t					difference_type;	//
		private:
			pointer									_element;			// element pointed by the iterator

		public:
			random_access_iterator( void ): _element(NULL){}
			random_access_iterator( pointer ptr ): _element(ptr){}
			random_access_iterator( const random_access_iterator& rhs ){ *this = rhs; }
			~random_access_iterator( void ){}

			pointer base() const { return _element; }

			random_access_iterator& operator=( const random_access_iterator& rhs) // assignment operator
			{
				if (this == &rhs)
					return (*this);
				this->_element = rhs._element;
				return (*this);
			}

			reference operator[]( int index )				// a reference to the element placed at index
			{
				return (*(_element + index));
			}

			operator const_iterator() const
			{
				return const_iterator(_element);
			}

			iterator operator+( difference_type n ) const	// a iterator where the element is pointed at this + n in memory
			{
				return (_element + n);
			}

			iterator operator-( difference_type n ) const	// a iterator where the element is pointed at this - n in memory
			{
				return (_element - n);
			}

			pointer operator->( void )						// return lvalue (pointer to the element)
			{
				return (_element);
			}

			reference operator*( void )						// return rvalue (value where point the pointer)
			{
				return (*(_element));
			}

			iterator& operator++( void )					// pre increment
			{
				_element++;
				return (*this);
			}

			iterator operator++( int )						// post increment
			{
				iterator it = *this;
				++(*this);
				return (it);
			}

			iterator& operator--( void )					// pre decrement
			{
				_element--;
				return (*this);
			}

			iterator operator--( int )						// post decrement
			{
				iterator it = *this;
				--(*this);
				return (it);
			}

			iterator operator+=( difference_type n ) const	// a reference to the element placed at the actual pointer memory + n
			{
				_element += n;
				return (*this);
			}

			iterator operator-=( difference_type n ) const	// a reference to the element placed at the actual pointer memory - n
			{
				_element -= n;
				return (*this);
			}

			bool operator==( const iterator& it ) const		// checks if lhs is equal to rhs
			{
				return (_element == it._element);
			}

			bool operator!=( const iterator& it ) const		// checks if lhs is not equal to rhs
			{
				return (_element != it._element);
			}

			bool operator>=( const iterator& it ) const		// checks if lhs is greater or equal then rhs
			{
				return (_element >= it._element);
			}

			bool operator>( const iterator& it ) const		// checks if lhs is greater then rhs
			{
				return (_element > it._element);
			}

			bool operator<=( const iterator& it ) const		// checks if lhs is less or equant then rhs
			{
				return (_element <= it._element);
			}

			bool operator<( const iterator& it ) const		// checks if lhs is less then rhs
			{
				return (_element < it._element);
			}
	};

	template<class T>
	bool operator==(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){

		return lhs.base() == rhs.base();
	}

	template<class T>
	bool operator!=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){
		return lhs.base() != rhs.base();
	}

	template<class T>
	bool operator<(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){
		return lhs.base() < rhs.base();
	}

	template<class T>
	bool operator<=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){
		return lhs.base() <= rhs.base();
	}

	template<class T>
	bool operator>(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){
		return lhs.base() > rhs.base();
	}

	template<class T>
	bool operator>=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs){
		return lhs.base() >= rhs.base();
	}

	template<class T_L, class T_R>
	bool operator==(const ft::random_access_iterator<T_R>& lhs, const ft::random_access_iterator<T_L>& rhs){
		return lhs.base() == rhs.base();
	}

	template<class T_L, class T_R>
	bool operator!=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs){
		return lhs.base() != rhs.base();
	}

	template<class T_L, class T_R>
	bool operator<(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs){
		return lhs.base() < rhs.base();
	}

	template<class T_L, class T_R>
	bool operator<=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs){
		return lhs.base() <= rhs.base();
	}

	template<class T_L, class T_R>
	bool operator>(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs){
		return lhs.base() > rhs.base();
	}

	template<class T_L, class T_R>
	bool operator>=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs){
		return lhs.base() >= rhs.base();
	}
}

#endif //RANDOM_ACCESS_ITERATOR_HPP
