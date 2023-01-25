/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_print.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:27:52 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/25 18:48:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_PRINT_TPP
#define RBT_PRINT_TPP

#include "./RBT.hpp"

namespace ft
{
	/* Public */
	template <RBT_TEMPLATE>
	void RBT_CLASS::preOrder( void ) const
	{
		preOrderPrint(this->root);
		std::cout << std::endl;
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::postOrder( void ) const
	{
		postOrderPrint(this->root);
		std::cout << std::endl;
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::inOrder( void ) const
	{
		inOrderPrint(this->root);
		std::cout << std::endl;
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::prettyPrint( void ) const
	{
		if (root)
			printAux(root, "", true);
	}

	/* Private */
	template <RBT_TEMPLATE>
	void RBT_CLASS::preOrderPrint(node_ptr node) const
	{
		if (node != TNULL)
		{
			std::cout << KeyOfValue()(node->data) << " ";
			preOrderPrint(node->left);
			preOrderPrint(node->right);
		}
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::inOrderPrint(node_ptr node) const
	{
		if (node != TNULL)
		{
			postOrderPrint(node->left);
			std::cout << KeyOfValue()(node->data) << " ";
			postOrderPrint(node->right);
		}
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::postOrderPrint(node_ptr node) const
	{
		if (node != TNULL)
		{
			postOrderPrint(node->left);
			postOrderPrint(node->right);
			std::cout << KeyOfValue()(node->data) << " ";
		}
	}
	template <RBT_TEMPLATE>
	void RBT_CLASS::printAux(node_ptr root, std::string indent, bool last) const
	{
		if (root != TNULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "     ";
			}
			else
			{
				std::cout << "L----";
				indent += "|     ";
			}
			std::cout << KeyOfValue()(root->data) << std::endl;
			printAux(root->left, indent, false);
			printAux(root->right, indent, true);
		}
	}
}

#endif
