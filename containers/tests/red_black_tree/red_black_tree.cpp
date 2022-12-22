/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/21 23:53:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/RBT.hpp"
#include "../../utils/pair.hpp"

#define KEY		std::string
#define VALUE	int
#define KEYOF	ft::pair<KEY, VALUE>
#define COMPARE	std::less<KEY>


template <typename T>
struct keyofvalue
{
	KEY operator()(const T& v) const
	{
		return (v.first);
	}
};

int main( void )
{
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree;

	tree.insert(KEYOF("Lisa", 22), tree.get_root());
}



