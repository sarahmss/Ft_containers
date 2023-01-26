/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:59:57 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/26 14:39:39 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vectro<T>>
	class stack
	{
		public:
			typedef Container								container_type
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;
		protected:
			Container _c;

		public:
			/********************* Member Functions **********************/
			explicit stack(const container_type& container = Container()) : _c(container){}
			stack(const stack &other) : _c(other._c) {}
			~stack( void ){}
			stack &operator=(const stack &other)
			{
				_containter = other._c;
				return (*this);
			}
			/********************* Element access **********************/
			reference	top( void ) { return (_c.back()); }
			reference	top( void ) const { return (_c.back()); }
			/********************* Capacity **********************/
			bool		empty( void )  const { return (_c.empty());}
			size_type	size( void ) const { return (_c.size()) };
			/********************* Modifiers **********************/
			void		push( const value_type& value ) { _c.push_back(value); }
			void		pop( void ) { _c.pop_back(); }
	}
			/********************* operators **********************/
			template <class T, class Container>
			bool operator==(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return (lhs._c == rhs._c); }
						template <class T, class Container>
			bool operator!=(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return (!(lhs == rhs)); }
						template <class T, class Container>
			bool operator<(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return (lhs._c < rhs._c); }
						template <class T, class Container>
			bool operator<=(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return (!(rhs < lhs)); }
			bool operator>(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return ( rhs < lhs); }
						template <class T, class Container>
			bool operator>=(const stack<T, Container>& lhs,
							const stack<T, Container>& rhs ) { return (!(lhs < rhs)); }
}

#endif //STACK_HPP
