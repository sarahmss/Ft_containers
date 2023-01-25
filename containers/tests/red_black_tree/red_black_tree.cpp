/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 18:37:49 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/RBT.hpp"
#include "../../utils/pair.hpp"
/*
	Covering:

		insert:				OK
		double insertion:	OK
		search:				OK
		erase:
*/
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
	std::cout << "------ Instanciating a default red black tree ---------" << std::endl;
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree1;
	tree1.insert(KEYOF("Lisa", 23), tree1.get_root());
	tree1.insert(KEYOF("Carlo", 24), tree1.get_root());
	tree1.insert(KEYOF("Ana", 25));
	tree1.insert(KEYOF("Julia", 12));
	std::cout << "Pre Order: ";
	tree1.preOrder();
	std::cout << "Post Order: ";
	tree1.postOrder();
	std::cout << "In Order: ";
	tree1.inOrder();
	std::cout << "Pretty print tree1: \n";
	tree1.prettyPrint();

	std::cout << "------------Instanciating a copy red black tree--------------" << std::endl;
	ft::RedBlackTree<KEY, KEYOF, keyofvalue<KEYOF>, COMPARE> tree2(tree1);
	tree2.insert(KEYOF("Bia", 12));
	std::cout << "Pretty print tree2: \n";
	tree2.prettyPrint();

	std::cout << "------------ Searching Bia in tree2--------------" << std::endl;
	ft::Node<KEYOF>	*node = tree2.search("Bia");
	std::cout << node->data.first << " founded";
	std::cout << " with sucessor " << tree2.successor(node)->data.first;
	std::cout << " and predecessor " << tree2.predecessor(node)->data.first;
	std::cout << std::endl;
	std::cout << "------------ Deleting Ana in tree2--------------" << std::endl;
	tree2.erase("Ana");
	tree2.prettyPrint();
	return (0);
}



