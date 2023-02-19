/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:59:57 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/19 15:48:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;
		protected:
			Container c;

		public:
			/********************* Member Functions **********************/
			explicit stack(const container_type& container = Container()) : c(container){}
			stack(const stack &other) : c(other.c) {}
			~stack( void ){}
			stack &operator=(const stack &other)
			{
				c = other.c;
				return (*this);
			}
			/********************* Element access **********************/
			reference	top( void ) { return (c.back()); }
			reference	top( void ) const { return (c.back()); }
			/********************* Capacity **********************/
			bool		empty( void )  const { return (c.empty());}
			size_type	size( void ) const { return (c.size()); }
			/********************* Modifiers **********************/
			void		push( const value_type& value ) { c.push_back(value); }
			void		pop( void ) { c.pop_back(); }

			template <class Temp, class Cont>
			friend bool operator==(const stack<Temp, Cont>& lhs, const stack<Temp, Cont>& rhs);
			template <class Temp, class Cont>
			friend bool operator<(const stack<Temp, Cont>& lhs, const stack<Temp, Cont>& rhs);
	};
			/********************* operators **********************/
			template <class Temp, class Cont>
			bool operator==(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return (lhs.c == rhs.c); }
			template <class Temp, class Cont>
			bool operator!=(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return (!(lhs == rhs)); }
			template <class Temp, class Cont>
			bool operator<(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return (lhs.c < rhs.c); }
			template <class Temp, class Cont>
			bool operator<=(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return (!(rhs < lhs)); }
			template <class Temp, class Cont>
			bool operator>(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return ( rhs < lhs); }
			template <class Temp, class Cont>
			bool operator>=(const stack<Temp, Cont>& lhs,
							const stack<Temp, Cont>& rhs ) { return (!(lhs < rhs)); }
}

#endif //STACK_HPP
