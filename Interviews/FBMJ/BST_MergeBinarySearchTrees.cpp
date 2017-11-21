/*
 * BST_MergeBinarySearchTrees.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: JoanneY1
 */

#include "../Leetcode/BST.h"

using namespace std;
/*
 * Merge two binary search tree into a single binary search tree
 */

/*
 * first we need to create a iterator for binary search tree
 */
class BSTIterator
{
public:
	BSTIterator(TreeNode* root)
	{
		pushLeft(root);
	}

	bool hasNext()
	{
		return !table.empty();
	}

	int next()
	{
		TreeNode* curr = table.top();
		table.pop();
		pushLeft(curr->right);
		return curr->right;
	}

	// returns the value but not pop out the tree node
	int peek()
	{
		return table.top()->val;
	}

	void pushLeft(TreeNode* node)
	{
		while(node)
		{
			table.push(node);
			node = node->left;
		}
	}

	stack<TreeNode*> table;
};

/*
 * go through two trees and get the inorder order
 */
vector<int> flatTwoBst(TreeNode* root1, TreeNode* root2)
{
	BSTIterator iter1 = BSTIterator(root1);
	BSTIterator iter2 = BSTIterator(root2);

	vector<int> inorder;

	while(iter1.hasNext() || iter2.hasNext())
	{
		if(!iter1.hasNext()) inorder.push_back(iter2.next());
		else if(!iter2.hasNext()) inorder.push_back(iter1.next());
		if(iter1.peek() < iter2.peek())
		{
			inorder.push_back(iter1.next());
		}
		else
		{
			inorder.push_back(iter2.next());
		}
	}

	return inorder;
}

/*
 * reconstruct tree using inorder traversal
 */
TreeNode* buildBstWithInorder(vector<int>& inorder, int lhs, int rhs)
{
	if(lhs > rhs) return NULL;

	int mid = lhs + (rhs - lhs)/2;
	TreeNode* node = new TreeNode(inorder[mid]);

	node->left = buildBstWithInorder(inorder, lhs, mid-1);
	node->right = buildBstWithInorder(inorder, mid+1, rhs);

	return node;
}

TreeNode* mergeTwoBst(TreeNode* root1, TreeNode* root2)
{
	vector<int> inorder = flatTwoBst(root1, root2);
	return buildBstWithInorder(inorder, 0, inorder.size()-1);
}
