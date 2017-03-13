/******************************************************************************/
/**
* Question: #116 Populating Next Right Pointers in Each Node
* Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

* Populate each next pointer to point to its next right node. If there is no next right node, 
* the next pointer should be set to NULL.
* Initially, all next pointers are set to NULL.

* Note:
* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
/*****************************************************************************/

#include "BST.h"
#include <queue>

using namespace std;

void connect1(TreeLinkNode *root) 
{
	if (!root) return;
	queue<TreeLinkNode*> layer;
	layer.push(root);
	while (!layer.empty())
	{
		int len = layer.size();
		for (int i = 0; i < len; i++)
		{
			TreeLinkNode * curr = layer.front();
			layer.pop();
			if (i < len-1) curr->next = layer.front();
			if(curr->left)layer.push(curr->left);
			if(curr->right)layer.push(curr->right);
		}
	}
}

void connect2(TreeLinkNode *root)
{
	if (!root || (!root->left && !root->right)) return;
	TreeLinkNode * curr = root, *nextLayer = root->left;
	while (nextLayer)
	{
		while (curr)
		{
			curr->left->next = curr->right;
			if (curr->next) curr->right->next = curr->next->left;
			curr = curr->next;
		}
		curr = nextLayer;
		nextLayer = curr->left;
	}
}