
# in binary trees, each node has two children
# here we will store two references to the left and right childs

class TreeNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

	def __str__(self):
		return str(self.data)


# start point to use methods
class BinaryTree:
	def __init__(self, data):
		node = TreeNode(data)
		self.root = node

if __name__ == "__main__":
	tree = BinaryTree(7)
	tree.root.left = TreeNode(18)
	tree.root.right = TreeNode(14)

	print(tree.root)
	print(tree.root.left)
	print(tree.root.right)

