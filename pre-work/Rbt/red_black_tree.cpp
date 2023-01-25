/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 17:13:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RBT.hpp"
#include "./pair.hpp"

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

template <typename T>
struct valueofvalue
{
	VALUE operator()(const T& v) const
	{
		return (v.second);
	}
};

int main( void )
{
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree1;
//	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree2(tree1);

	tree1.insert(KEYOF("Lisa", 23), tree1.get_root());
	tree1.insert(KEYOF("Carlo", 24), tree1.get_root());
	tree1.insert(KEYOF("Ana", 25), tree1.get_root());

	std::cout << "Pre Order: ";
	tree1.preOrder();
	std::cout << "Post Order: ";
	tree1.postOrder();
	std::cout << "In Order: ";
	tree1.inOrder();

	return (0);
}



