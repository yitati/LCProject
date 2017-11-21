
#include "../Leetcode/BST.h"

// Q2 - isSymmetric
bool isSymmetric(TreeNode * a, TreeNode * b)
{
	if (!a && !b) return true;
	else if (!a || !b) return false;
	else
	{
		if (a->val != b->val) return false;
		return isSymmetric(a->left, b->right) && isSymmetric(a->left, b->right);
	}
}

bool isSymmatricTree(TreeNode * root)
{
	if (!root) return true;
	return isSymmetric(root->left, root->right);
}

// Time complexity analysis - 
// O(n) - draw the recursion tree
// first layer called O(2), second layer O(4) .... so total nodes n
// total times that the recursion function is called O(n/2)
// So time complexity is O(n)



// Q3 - tweak the tree and judge if it is identical
bool isTweakedIdentical(TreeNode * a, TreeNode * b)
{
	// base case
	if (!a && !b) return true;
	else if (!a || !b) return false;
	else if (a->val != b->val) return false;

	// recursion rule
	return (isTweakedIdentical(a->left, b->left) && isTweakedIdentical(a->right, b->right)) ||  // case 1
		(isTweakedIdentical(a->left, b->right) && isTweakedIdentical(a->right, b->left));       // case 2
}
// Time complexity -
// The level of the quadra-tree is log_2(n)
// Total number of node in the recursion tree is 4^(log_2(n)) = 2^(2log_2(n)) = 2(log_2(n^2)) = n^2
// So time complexity is O(n^2)






