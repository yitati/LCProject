/******************************************************************************
* Question: #117 Populating Next Right Pointers In Each Node II
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
* Note:
* You may only use constant extra space.

For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 * Follow-up:
 * company tag: Facebook
 * What if we need to link the last node to the next layer first?
*****************************************************************************/

#include "BST.h"

using namespace std;

void connect(TreeLinkNode *root) {
	if (!root || (!root->left && !root->right)) return;
	TreeLinkNode * curr = root;
	TreeLinkNode * nextLayer = curr->left ? curr->left : curr->right;
	while (nextLayer)
	{
		TreeLinkNode * tmp = NULL;
		while (curr)
		{
			if (curr->left)
			{
				if (tmp) tmp->next = curr->left;
				tmp = curr->left;
			}
			if (curr->right)
			{
				if (tmp) tmp->next = curr->right;
				tmp = curr->right;
			}
			curr = curr->next;
		}
		// if follow-up
		// curr->next = nextLayer;
		curr = nextLayer;
		while (nextLayer)
		{
			if (nextLayer->left)
			{
				nextLayer = nextLayer->left;
				break;
			}
			else if (nextLayer->right)
			{
				nextLayer = nextLayer->right;
				break;
			}
			else nextLayer = nextLayer->next;
		}
	}
}
