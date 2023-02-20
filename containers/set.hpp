/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:41:08 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/19 22:57:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef set_HPP
#define set_HPP

#include "./utils/RBT.hpp"
#include "./utils/pair.hpp"

namespace ft
{
	template<	class Key,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Key>
	> class set
	{
		template <typename V>
		struct keyofvalue
		{
			Key operator()(const V& v) const
			{
				return (v);
			}
		};

		public:
			typedef Key												key_type;
			typedef Key												value_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::const_reference				const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;

		private:
			typedef ft::RedBlackTree<key_type,
									value_type,
									keyofvalue<value_type>,
									key_compare,
									Allocator>						rbt_type;
			rbt_type	_tree;

		public:
			typedef typename rbt_type::size_type					size_type;
			typedef typename rbt_type::difference_type				difference_type;
			typedef typename rbt_type::allocator_type				allocator_type;
			typedef typename rbt_type::iterator						iterator;
			typedef typename rbt_type::const_iterator				const_iterator;
			typedef typename rbt_type::reverse_iterator				reverse_iterator;
			typedef typename rbt_type::const_reverse_iterator		const_reverse_iterator;

		public:
		/********************* Member Functions **********************/

		explicit set(const key_compare& comp=Compare(), const Allocator &alloc = Allocator())
					: _tree(comp, alloc) { return; }

		template <class InputIt>
		set ( InputIt first, InputIt last,
			const key_compare& comp = Compare(),
			const Allocator &alloc = Allocator()) : _tree(comp, alloc)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		set (const set &other) : _tree(other._tree) { return; }

		~set ( void ){ clear(); }

		set &operator=(const set &other)
		{
			_tree = other._tree;
			return (*this);
		}

		allocator_type get_allocator( void ) const { return (_tree.get_allocator()); }

		/********************* Iterators **********************/
		iterator				begin( void ) { return (_tree.begin()); }
		const_iterator			begin( void ) const { return (_tree.begin()); }
		iterator				end( void ) { return (_tree.end()); }
		const_iterator			end( void ) const { return (_tree.end()); }
		reverse_iterator		rbegin( void ) { return (_tree.rbegin()); }
		const_reverse_iterator	rbegin( void ) const { return (_tree.rbegin()); }
		reverse_iterator		rend( void ) { return (_tree.rend()); }
		const_reverse_iterator	rend( void ) const { return (_tree.rend()); }
		/********************* Capacity **********************/
		bool					empty( void ) const { return (_tree.empty()); }
		size_type				size( void ) const { return (_tree.size()); }
		size_type				max_size( void ) const { return (_tree.max_size()); }
		/********************* Modifiers **********************/
		void						clear( void ){_tree.clear();}
		ft::pair<iterator, bool>	insert(const value_type& value)
		{
			iterator element = find(value);
			if (element != end())
				return (ft::make_pair(element, false));
			iterator element2 = _tree.simple_insert(value);
			return (ft::make_pair(element2, true));
		}
		iterator					insert(iterator pos, const value_type& value)
		{
			iterator element = find(value);
			if (element != end())
				return (element);
			_tree.insert(value, pos.base());
			return (find(value));
		}
		template <class InputIt>
		void						insert(InputIt first, InputIt last)
		{
			while(first != last)
			{
				insert(*first);
				++first;
			}
		}
		void						erase( iterator pos ){_tree.erase(*pos);}
		void						erase( iterator first, iterator last )
		{
			iterator it;
			while (first != last)
			{
				it = first;
				++first;
				erase(it);
			}

		}
		size_type					erase( const value_type& value)
		{
			if (find(value) != end())
			{
				_tree.erase(value);
				return (1);
			}
			return (0);
		}
		void	swap( set& other ) { _tree.swap(other._tree); }
		/********************* Lookup **********************/
		size_type				count(const value_type& value) const
		{
			const_iterator	it = find(value);
			if (it == _tree.end())
				return (0);
			return (1);
		}
		iterator				find(const value_type& value)
		{
			iterator element(_tree.search(value));
			return (element);
		}
		const_iterator			find(const value_type& value) const
		{
			const_iterator element(_tree.search(value));
			return (element);
		}
		ft::pair<iterator, iterator> equal_range(const value_type& value)
		{
			iterator	upper = upper_bound(value);
			iterator	lower = lower_bound(value);
			return (ft::make_pair(lower, upper));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const value_type& value) const
		{
			const_iterator	upper = upper_bound(value);
			const_iterator	lower = lower_bound(value);
			return (ft::make_pair(lower, upper));
		}
		iterator				lower_bound (const value_type& value){return(_tree.lower_bound(value));}
		iterator				upper_bound (const value_type& value){return(_tree.upper_bound(value));}
		const_iterator			lower_bound (const value_type& value) const {return(_tree.lower_bound(value));}
		const_iterator			upper_bound (const value_type& value) const {return(_tree.upper_bound(value));}
		/********************* Observers **********************/
		key_compare				key_comp( void ) const { return (_tree.key_comp());}
		value_compare			value_comp( void ) const { return (value_compare(_tree.key_comp()));}

		template< class K, class C, class A >
		friend bool operator==(const set<K, C, A>& lhs,
								const set<K, C, A>& rhs);
		template< class K, class C, class A >
		friend bool operator<(const set<K, C, A>& lhs,
								const set<K, C, A>& rhs);
	};
		/********************* Opertators **********************/
		template< class K, class C, class A >
		bool operator==(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (lhs._tree == rhs._tree); }

		template< class K, class C, class A >
		bool operator!=(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (!(lhs == rhs)); }

		template< class K, class C, class A >
		bool operator<(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (lhs._tree < rhs._tree); }

		template< class K, class C, class A >
		bool operator<=(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (!(lhs > rhs)); }
				template< class K, class C, class A >
		bool operator>(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (rhs < lhs); }

		template< class K, class C, class A >
		bool operator>=(const set<K, C, A>& lhs,
						const set<K, C, A>& rhs)
		{ return (!(lhs < rhs)); }
}

#endif //set_HPP

