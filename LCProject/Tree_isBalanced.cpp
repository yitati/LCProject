#include "BST.h"
#include <algorithm>

int getHeight(TreeNode * root)
{
	if (root == NULL) return 0;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	return max(leftHeight, rightHeight) + 1;
}
// time coplexity for each level - O(n) (n is the number of nodes in the sub-tree rooted by given root)

bool isBalancedTree(TreeNode * root)
{
	if (!root) return true;
	int diff = getHeight(root->left) - getHeight(root->right);
	if (abs(diff) > 1) return false;
	return isBalancedTree(root->left) && isBalancedTree(root->right);
}

// time complexity - every level time complexity is O(n)
// there are logn levels, so total time complexity is O(nlogn)



