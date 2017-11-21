/******************************************************************************
* Question: #450 Delete Node in a BST
* company tag: eBay
* Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
* Return the root node reference (possibly updated) of the BST.
* Basically, the deletion can be divided into two stages:
* Search for a node to remove.
* If the node is found, delete the node.
* Note: Time complexity should be O(height of tree).
*****************************************************************************/

#include "../Leetcode/BST.h"
using namespace std;

// helper function to get the right most node value
int getRightMost(TreeNode* root)
{
	while(root->right) root = root->right;
	return root->val;
}

// when delete a tree node there can be some different situations
// 1. when node is the value to be deleted
//    1.1 when root does not have left child or right child, just delete it.
//    1.2 when root does not have left child, delete root and return right child
//    1.3 when root does not have right child, delete root and return left child
//    1.4 when both left and right child exist, find the right most value of left subtree
//        to be the new root value, and delete rightMost value from left tree
// 2. when node->val < key, delete from left tree
// 3. when node->val > key, delete from right tree

TreeNode* deleteNode(TreeNode* root, int key)
{
	if(!root) return NULL;
	if(root->val < key) root->right = deleteNode(root->right, key);
	else if(root->val > key) root->left = deleteNode(root->left, key);
	// when root is the node to be deleted
	else
	{
		if(!root->left && !root->right)
		{
			delete root;
			return NULL;
		}
		if(!root->left)
		{
			TreeNode* right = root->right;
			delete root;
			return right;
		}
		if(!root->right)
		{
			TreeNode* left = root->left;
			delete root;
			return left;
		}
		int rightMost = getRightMost(root->left);
		root->val = rightMost;
		root->left = deleteNode(root->left, rightMost);
	}
	return root;
}
/*
int main(int argc, char** argv)
{
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);

	node5->left = node3;
	node5->right = node6;
	node3->left = node2;
	node3->right = node4;
	node6->right = node7;

	printPretty(node5, 1, 0, cout);

	node5 = deleteNode(node5, 3);

	printPretty(node5, 1, 0, cout);

}
*/




