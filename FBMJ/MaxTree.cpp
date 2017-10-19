/*
 * MaxTree.cpp
 *
Given an integer array with no duplicates. A max tree building on this array is defined as follow:
The root is the maximum number in the array The left subtree and right subtree are the max trees of the
subarray divided by the root number. Construct the max tree by the given array.
Example Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:

    6
   / \
  5   3
 /   / \
2   0   1

Challenge O(n) time and memory.
 */

#include <vector>
#include "../LCProject/BST.h"

using namespace std;


/*
 * everytime find the max value of the tree, then its left side will be its left subtree
 * and its right side will be its right subtree
 */
TreeNode* getTreeNode(vector<int> inorder, int start, int end)
{
	if(start > end) return NULL;
	int idx = start, maxVal = inorder[start];
	for(int i=start; i<end; i++)
	{
		if(inorder[i] > maxVal)
		{
			maxVal = inorder[i];
			idx = i;
		}
	}

	TreeNode* root = new TreeNode(maxVal);
	root->left = getTreeNode(inorder, start, idx-1);
	root->right = getTreeNode(inorder, idx+1, end);

	return root;
}

/*
 * use insertion solution
 */
TreeNode* getMaxTree(TreeNode* root, int num)
{
	TreeNode* node = new TreeNode(num);
	if(!root) return node;

	if(root->val < node->val)
	{
		node->left = root;
		return node;
	}

	TreeNode* prev = root;
	TreeNode* tmp = root->right;
	while (tmp && tmp->val > num) // find the smallest number that is larger than num
	{
		prev = tmp;
		tmp = tmp->right;
	}
	prev->right = node;
	node->left = tmp;
	return root;

}

// recursion solution
TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    //return getTreeNode(nums, 0, nums.size()-1);
	TreeNode* root = NULL;
	for(int num : nums)
	{
		root = getMaxTree(root, num);
	}
	return root;
}





