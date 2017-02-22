/******************************************************************************/
/*
* Question: #230 Kth Smallest Element In a BST
* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

* Note:
* You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

* Follow up:
* What if the BST is modified (insert/delete operations) often and you need to find 
* the kth smallest frequently? How would you optimize the kthSmallest routine?

* Hint:
* Try to utilize the property of a BST.
* What if you could modify the BST node's structure?
* The optimal runtime complexity is O(height of BST).
*/
/*****************************************************************************/

#include "BST.h"
#include <stack>

using namespace std;


// solution 1 - do the inorder traversal we can find the kth element
int kthSmallest1(TreeNode* root, int k)
{
	if (root == NULL) return -1;
	stack<TreeNode *> inorder;
	TreeNode * curr = root;
	while ((curr || !inorder.empty()) && k)
	{
		if (curr) // this is the push block
		{
			inorder.push(curr);
			curr = curr->left;
		}
		else // this is the pop block
		{
			TreeNode * node = inorder.top();
			if (k == 1) return node->val;
			inorder.pop();
			k--;
			if (node->right) curr = node->right;
		}
	}

	return -1;
}


// solution 2 - find how many element in left tree
int countTreeNodes(TreeNode * root)
{
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

int kthSmallest2(TreeNode* root, int k) 
{
	if (!root) return -1;
	int countLeft = countTreeNodes(root->left);
	if (countLeft == k - 1) return root->val;
	else if (countLeft > k-1) return kthSmallest2(root->left, k);
	else return kthSmallest2(root->right, k - countLeft - 1);
}