/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/10 22:04:42 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./red_black_tree.hpp"

int main ()
{
	RedBlackTree<int> bst;
	bst.insert(8);
	bst.insert(18);
	bst.insert(5);
	bst.insert(15);
	bst.insert(17);
	bst.insert(25);
	bst.insert(40);
	bst.insert(80);
	bst.deleteNode(25);
	bst.prettyPrint();
	return 0;
}
