/*
 * Mianjing: Complete Tree
 * company tag: Facebook
 * Check a binary tree is completed or not. A complete binary tree is a binary tree that every level
 * is completed filled except the deepest level, all nodes must be as left as possible. See more
 * definition.
 * Example
    1
   / \
  2   3
 /
4
is a complete binary tree
    1
   / \
  2   3
   \
    4
is not a complete binary tree.

 */

/*
 * Solution 1 - BFS
 * Do a level traversal starting from root. In the traversal, once a node is found which is NOT
 * a full node, all the following nodes must be leaf nodes. User the BFS by queue, when first
 * find a node which doesn't have left or right child, if find next has any child, this tree is
 * definitely not a complete binary tree.
 */

#include "BST.h"
#include <queue>

using namespace std;

bool isComplete_bfs(TreeNode* root)
{
	if(!root) return true;

	queue<TreeNode*> treeQueue;
	treeQueue.push(root);
	bool notComplete = false;

	while(!treeQueue.empty())
	{
		TreeNode* curr = treeQueue.front();
		treeQueue.pop();
		if(curr->left)
		{
			treeQueue.push(curr->left);
			if(notComplete) return false;
		}
		else notComplete = true;
		if(curr->right)
		{
			treeQueue.push(curr->right);
			if(notComplete) return false;
		}
		else notComplete = true;
	}
	return true;
}

/*
 * Solution 2 - recursion
 * http://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/
 * In a binary tree if root is assgined with index i, then it's left child should have index 2*i+1
 * and its right child should have index 2*i+2.
 */

// helper function that counts node in a tree
int getNumOfTreeNodes(TreeNode* root)
{
	if(!root) return 0;
	return getNumOfTreeNodes(root->left) + getNumOfTreeNodes(root->right) + 1;
}

bool isComplete_recursion(TreeNode* root, int index, int total)
{
	if(!root) return true;
	if(index >= total) return false;
	return isComplete_recursion(root->left, 2*index+1, total) &&
			isComplete_recursion(root->right, 2*index+2, total);
}



