/*
 * find the successor in the binary search tree
 * recursive solution, time complexity is O(h), h is the depth of the tree
 */
#include <../LCProject/BST.h>

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	if(!root || !p) return NULL;
	if(root->val <= p->val) return inorderSuccessor(root->right, p);
	else
	{
		TreeNode* leftSuc = inorderSuccessor(root->left, p);
		return leftSuc ? leftSuc : root;
	}
}

/*
 * iterative way, if p has right subtree, then the successor will be the left most node of right subtree
 * else, traverse from root to find it
 * if root->val > p->val, set root as suc and find suc in root's left subtree,
 * else find it in right subtree
 */

static TreeNode* leftMost(TreeNode* node)
{
	TreeNode* curr = node;
	while(curr->left)
	{
		curr = curr->left;
	}
	return curr;
}

TreeNode* inorderSuccessor_inorder(TreeNode* root, TreeNode* p)
{
	if(p->right) return leftMost(p->right);
	TreeNode* suc = NULL;

	// otherwise traverse from root
	while(root)
	{
		if(root->val > p->val)
		{
			suc = root;
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}

	return suc;
}

/*
 * inorder predessor
 */
TreeNode * inorderPredessor(TreeNode * root, TreeNode * p)
{
	if (!root) return NULL;
	if (root->val >= p->val) return inorderPredessor(root->left, p);
	else
	{
		TreeNode * right = inorderPredessor(root->right, p);
		return right ? right : root;
	}
}
