/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_print.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:35:56 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/12 20:16:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//	visit: node->left_subtree->right_subtree
void preOrder( void ) const {
	preOrderPrint(this->root);
}

//	visit: left_subtree->right_subtree->node
void postOrder( void ) const {
	postOrderPrint(this->root);
}
//	visit: left_subtree->node->right_subtree
void inOrder( void ) const {
	inOrderPrint(this->root);
}

/*
	@brief:
		in pre-order traversal we first visit the node
		and recursively visit all its children
*/
void preOrderPrint(node_ptr node)
{
	if (node != TNULL)
	{
		std::cout << node->data << " ";
		preOrderPrint(node->left);
		preOrderPrint(node->right);
	}
}

/*
	@brief:
		in in-order traversal we visit the left subtree recursively,
		visit the node and finally visit the right subtree.
*/
void inOrderPrint(node_ptr node)
{
	if (node != TNULL)
	{
		postOrderPrint(node->left);
		std::cout << node->data << " ";
		postOrderPrint(node->right);
	}
}

/*
	@brief:
		in post-order traversal we first visit the children if the node
		and only then we visit the node
*/
void postOrderPrint(node_ptr node)
{
	if (node != TNULL)
	{
		postOrderPrint(node->left);
		postOrderPrint(node->right);
		std::cout << node->data << " ";
	}
}

void printAux(node_ptr root, std::string indent, bool last)
{
	if (root != NULL)
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
		std::string sColor = root->color ? "RED" : "BLACK";
		std::cout << root->data << "("<< sColor <<")" << std::endl;
		printAux(root->left, indent, false);
		printAux(root->right, indent, true);
	}
}

void prettyPrint( void )
{
	if (root)
		printAux(this->root, "", true);
}
