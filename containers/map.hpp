/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:53:05 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/16 14:16:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/RBT.hpp"
#include "./utils/pair.hpp"
#include "./utils/equal.hpp"
#include "./utils/lexicographicalCompare.hpp"

namespace ft
{
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		template <typename V>
		struct keyofvalue
		{
			Key operator()(const V& v) const
			{
				return (v.first);
			}
		};

		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<key_type, mapped_type>					value_type;
			typedef Compare											key_compare;
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

			class value_compare : public std::binary_function <value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				protected:
					Compare comp;
					explicit value_compare(Compare c) : comp(c){}
				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}
			};

		public:
		/********************* Member Functions **********************/

		explicit map(const key_compare& comp = key_compare(), const allocator_type &alloc = Allocator())
					: _tree(comp, alloc) { return; }

		template <class InputIt>
		map ( InputIt first, InputIt last,
			const key_compare& comp = Compare(),
			const allocator_type &alloc = Allocator()) : _tree(comp, alloc)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		map (const map &other) : _tree(other._tree) { return; }

		~map ( void ){ clear(); }

		map &operator=(const map &other)
		{
			_tree = other._tree;
			return (*this);
		}

		allocator_type get_allocator( void ) const { return (_tree.get_allocator()); }
		/********************* Element access **********************/

		mapped_type				&at( const key_type& key)
		{
			mapped_type	element = _tree.search(key);
			if (element == this->end())
				throw std::out_of_range(" Out of bounds exception" );
			return (element);
		}
		const mapped_type		&at( const key_type& key) const
		{
			mapped_type	element = _tree.search(key);
			if (element == this->end())
				throw std::out_of_range(" Out of bounds exception" );
			return (element);
		}
		mapped_type&			operator[](const key_type& key)
		{
			iterator element = this->find(key);

			if (element == this->end())
				this->insert(ft::make_pair(key, mapped_type()));
			element = this->find(key);
			return ((*element)->second);
		}

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
			iterator element = find(value.first);
			if (element != end())
				return (ft::make_pair(element, false));
			iterator element2 = _tree.simple_insert(value);
			return (ft::make_pair(element2, true));
		}
		iterator					insert(iterator pos, const value_type& value)
		{
			iterator element = find(value.first);
			if (element != end())
				return (element);
			_tree.insert(value, pos.base());
			return (_tree.find(value.first));
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
		void						erase( iterator pos ){_tree.erase(pos->first);}
		void						erase( iterator first, iterator last )
		{
			iterator it;
			while (first != last)
			{
				it = first;
				++first;
				_tree.erase(it->first);
			}

		}
		size_type					erase( const key_type& key)
		{
			if (find(key) != end())
			{
				_tree.erase(key);
				return (1);
			}
			return (0);
		}
		void						swap( map& other ) { _tree.swap(other->_tree); }
		/********************* Lookup **********************/
		size_type				count(const key_type& key) const
		{
			const_iterator	it = _tree.find(key);
			if (it == _tree.end())
				return (0);
			return (1);
		}
		iterator				lower_bound (const key_type& key){return(_tree.lower_bound(key));}
		iterator				upper_bound (const key_type& key){return(_tree.upper_bound(key));}
		const_iterator			lower_bound (const key_type& key) const {return(_tree.lower_bound(key));}
		const_iterator			upper_bound (const key_type& key) const {return(_tree.upper_bound(key));}
		iterator				find(const key_type& key)
		{
			iterator element(_tree.search(key));
			return (element);
		}
		const_iterator			find(const key_type& key) const {return(_tree.find(key));}

		ft::pair<iterator, iterator> equal_range(const key_type& key)
		{
			iterator	upper = upper_bound(key);
			iterator	lower = lower_bound(key);
			return (ft::make_pair(lower, upper));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
		{
			const_iterator	upper = upper_bound(key);
			const_iterator	lower = lower_bound(key);
			return (ft::make_pair(lower, upper));
		}
		/********************* Observers **********************/
		key_compare				key_comp( void ) const { return (_tree.key_comp());}
		value_compare			value_comp( void ) const { return (value_comp(_tree.key_comp()));}
	};
		/********************* Opertators **********************/
		template< class Key, class T, class Compare, class Alloc >
		bool operator==(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		template< class Key, class T, class Compare, class Alloc >
		bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			return ((lhs > rhs) ? false : true);
		}
		template< class Key, class T, class Compare, class Alloc >
		bool operator>(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}
		template< class Key, class T, class Compare, class Alloc >
		bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs)
		{
			return ((lhs < rhs) ? false : true);
		}
			template< class Key, class T, class Compare, class Alloc >
		void	swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs )
		{
			lhs.swap(rhs);
		}

}

#endif //MAP_HPP

