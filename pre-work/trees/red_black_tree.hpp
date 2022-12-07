/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:25:53 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/07 00:16:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

/*
	-> A red black tree is  a binary search tree with following 5 properties:
		- Every node in T is either RED or BLACK
		- The ROOT node is BLACK
		- Every NULL node -that wich doesn't contain any keys- is black
		- If a node is red, both of its children are black
		- Every path from a ROOT node to a NULL node has the same number of black nodes
	-> Dynamic set operation:
		- Search
		- Predecessor
		- Succesor
		- insert
		- delete
	-> Insertion and deletion may violate the invariants creterials, to solve that we need to restru
		cture the tree through:
		- rotation is a transformation technique used to change the structure
		of bts without changing the order of the elements.
				a) Left rotation:
				b)  Right rotation:
		- Recolor: flips the color of a node
	-> it is called balanced search because its height is always in the order of O(log n)

				  [61]
				/      \
			   /	    \
			[52]        [85]
		    /   \       /   \
		   /	 \	   /	 \
		  /		  \   /		  \
		 [20]    [55](76)     (93)
		 /  \    / \
		(16) [N][N][N]
		/  \
	[N] [N]
*/

typedef enum e_color
{
	BLACK,
	RED
}			t_color;

template <typename T>
struct Node
{
	T		data;
	Node	*Parent;
	Node	*left;
	Node	*Right;
	t_color	color;
};

template <typename T>
class RedBlackTree
{
	pubic:
		typedef Node	*node_ptr;
		typedef T		value_type;
	private:
		node_ptr		root;
		node_ptr		TNULL;

		void initNullNode(node_ptr node, node_ptr parent)
		{
			node->data = value_type();
			node->parent = parent;
			node->left = NULL;
			node->right = NULL;
			node->color = BLACK;
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

		/*
			@brief: We can search a node with a given key (data) on a binary search tree.
					We start the process from the root node and move downward until we find
					the key we are searching for.
		*/
		node_ptr searchTreeAux(node_ptr node, value_type key)
		{
			if (node == TNULL || key == node->data)
				return node;
			if (key < node->data)
				return (searchTreeAux(node->left, key));
			return (searchTreeAux(node->right, key));
		}

		/*
			In a common binary search tree
				to insert a node k in the tree, we compare z with node x starting from the root node
				if z.key  > x.key then we continue process in the left subtree, otherwise we move
				to the right subtree.
			In a red black tree
				we color k red and check if its violated rbTree properties
				if it did, we fix it
					1. if P is black no rule is violated
					2. if T is empty we make K the root of the tree and color it black
					3. if P is red G node must be black
					3.1 if U is also red: -> P->black, U->black -> G->red
					3.2 if U is black or NULL: we need double or single rotations
					3.2.1
					3.2.2
					3.2.3
					3.2.4
		*/
		void fixInsert (node_ptr k)
		{
			node_ptr u;
			while (k->parent->color == RED)
			{
				if (k-parent == k->parent->parent->right)
				{
					u = k->parent->parent->left; // uncle
					if (u->color == RED) {
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = u->parent->parent->right;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						rightRotate(k->parent->parent);
					}
				}
				if (k == root)
					break;
			}
			root->color = BLACK;
		}

		/*
			@brief:
				To delete a node x from a RBT we follow the ordinary BST deletion process.
				let S be sibling and P parent nodes of x.

				- 3.1: S is red


		void fixDelete(node_ptr x)
		{
			node_ptr s;
			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED) // case 3.1
					{

					}
				}

		}*/

			void rbTransplant(node_ptr u, node_ptr v)
			{
				if (u->parent == NULL)
					root = v;
				else if ( u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
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
						std::cout << "L----"
						indent += "|     ";
					}
					std::string sColor = root->color ? RED : BLACK;
					std::cout << root->data << "("sColor")" << std::endl;
					printAux(root->left, indent, false);
					printAux(root->right, indent, true);
				}
			}


	public:
		RedBlackTree( void )
		{
			TNULL = new Node;
			TNULL->color = BLACK;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
		}

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
		// find the node with the given key
		node_ptr searchTree(value_type key) const {
			return (searchTreeAux(key));
		}
		// find the node with the minimum key
		node_ptr minimum(node_ptr node) {
			while (node->left != TNULL)
				node = node->left;
			return node;
		}
		// find the node with the maximum key
		node_ptr maximum(node_ptr node) {
			while (node->right != TNULL)
				node = node->right;
			return node;
		}
		/*
			find the successor of a given node
				left most element in right_subtree
		*/
		node_ptr successor(node_ptr x) {
			if (x->right != TNULL)
				return minimum(x->right);
			node_ptr y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
		/*
			find the predecessor of a given node
				right most element in left_subtree
		*/
		node_ptr predecessor(node_ptr x) {
			if (x->right != TNULL)
				return maximum(x->right);
			node_ptr y = x->parent;
			while (y != TNULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		/*
			rotate left at node x
				assume that x right child (y) is not null
				makes y the new root of subtree
				x becomes left child
				y's left child becomes x's right child
		*/
		void leftRotate(node_ptr x)
		{
			node_ptr y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}


		/*
			rotate right at node x
			(inverse from leftRotate)
		*/
		void rightRotate(node_ptr x)
		{
			node_ptr y = x->ledt;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		node_ptr getRoot( void ) { return (this->root); }
		void deleteNode(value_type data) { deleteNodeAux(this->root, data); }
		void prettyPrint( void )
		{
			if (root)
				printAux(this->root, "", true);
		}
}
int main ()
{
	RedBlackTree bst;
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



#endif //RED_BLACK_TREE_HPP


