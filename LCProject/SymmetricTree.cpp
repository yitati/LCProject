/******************************************************************************
* Question: #101 SymmetricTree
* company tag: LinkedIn
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

* Note:
* Bonus points if you could solve it both recursively and iteratively.
*****************************************************************************/

#include "BST.h"

using namespace std;

bool isSymmetricSub(TreeNode * leftTree, TreeNode * rightTree)
{
	if (!leftTree || !rightTree) return(leftTree == rightTree);
	if (leftTree->val != rightTree->val) return false;
	return isSymmetricSub(leftTree->left, rightTree->right) && isSymmetricSub(leftTree->right, rightTree->left);
}

bool isSymmetric(TreeNode* root)
{
	if (root == NULL) return true;
	if (!root->left && !root->right) return true;
	return isSymmetricSub(root->left, root->right);
}
