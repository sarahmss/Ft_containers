/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/24 19:30:24 by smodesto         ###   ########.fr       */
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
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree1;
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree2(tree1);

	tree1.insert(KEYOF("Lisa", 22), tree1.get_root());
}



