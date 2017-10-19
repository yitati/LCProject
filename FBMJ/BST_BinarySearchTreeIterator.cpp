/******************************************************************************
* Question: #173 Binary Search Tree Iterator
* company tag: Facebook, LinkedIn, eBay
* Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the
* root node of a BST.
* Calling next() will return the next smallest number in the BST.
* Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the
* height of the tree
*****************************************************************************/

#include "BST.h"
#include <vector>
#include <stack>

using namespace std;

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		pushLeft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !m_inorder.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode * curr = m_inorder.top();
		m_inorder.pop();
		pushLeft(curr->right);
		return curr->val;
	}

	void pushLeft(TreeNode * node)
	{
		while (node)
		{
			m_inorder.push(node);
			node = node->left;
		}
	}

	stack<TreeNode *> m_inorder;
};


/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
