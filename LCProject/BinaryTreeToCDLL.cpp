/*
 * Mianjing: Convert a Binary Tree to a Circular Doubly Link List
 * company tag: Facebook
 * http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/
 * Given a Binary Tree, convert it to a Circular Doubly Linked List (In-Place).
 * The left and right pointers in nodes are to be used as previous and next pointers
 * respectively in converted Circular Linked List.
 * The order of nodes in List must be same as Inorder of the given Binary Tree.
 * The first node of Inorder traversal must be head node of the Circular List.
 */

#include "BST.h"
#include "ListNode.h"

using namespace std;
// Here we are not actually create a struct of DLL node but to use tree node as dll node
// left will be same with prev
// right will be same with next

/*
 *  Helper function that will concatenate two DLLs.
 */
TreeNode* concatenate(TreeNode* left, TreeNode* right)
{
	if(!left) return right;
	if(!right) return left;

	TreeNode* leftTail = left->left;    // tail of left is the prev of left head
	TreeNode* rightTail = right->right;  // tail of right is the prev of right head

    leftTail->right = right;
    right->left = leftTail;

    rightTail->right = left;
    left->left = rightTail;

    return left;
}

/*
 *  Traverse the Tree in postorder
 *  and convert it to a circular linked list
 */
TreeNode* bTreeToCDLL(TreeNode* root)
{
	if(!root) return NULL;

	TreeNode* left = bTreeToCDLL(root->left);
	TreeNode* right = bTreeToCDLL(root->right);

	// make root left and right point to itself to make a single node circular list
	root->left = root;
	root->right = root;

	return concatenate(concatenate(left, root), right);
}

/*
 * Follow-up: Convert a given binary tree to doubly linked list
 * company tag: Facebook
 * http://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
 * Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers
 * in nodes are to be used as previous and next pointers respectively in converted DLL.
 * The order of nodes in DLL must be same as Inorder of the given Binary Tree.
 * The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
 */

// This problem is simpler as we don't need to create circular DLL, but a simple DLL.
// inorder solution - helper function will also keep the previous node
TreeNode* binaryTreeToDll(TreeNode* node, TreeNode*& prev)
{
	if(!node) return NULL;
	TreeNode* leftList = binaryTreeToDll(node->left, prev);
	if(prev != NULL)
	{
		prev->right = node;
	}
	node->left = prev;
	prev = node;
	TreeNode* rightList = binaryTreeToDll(node->right, prev);
	node->right = rightList;
	if(rightList) rightList->left = node;
	return leftList ? leftList : node;
}

TreeNode* bTreeToDll(TreeNode* root)
{
	if(!root) return NULL;
	TreeNode* prev = NULL;
	return binaryTreeToDll(root, prev);
}

/*
 * Follow-up: Convert doubly linked list to balanced binary tree
 * company tag: Facebook
 * http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
 * Given a Doubly Linked List which has data members sorted in ascending order. Construct a
 * Balanced Binary Search Tree which has same data members as the given Doubly Linked List.
 * The tree must be constructed in-place (No new node should be allocated for tree conversion)
 * Same to LC 109. Convert Sorted List to Binary Search Tree
 * Use solution to inorderly add nodes and build the tree, time complexity is O(n).
 */


int test_bTreeToCDLL()
{
	TreeNode* node10 = new TreeNode(10);
	TreeNode* node12 = new TreeNode(12);
	TreeNode* node15 = new TreeNode(15);
	TreeNode* node25 = new TreeNode(25);
	TreeNode* node30 = new TreeNode(30);
	TreeNode* node36 = new TreeNode(36);

	node10->left = node12;
	node10->right = node15;

	node12->left = node25;
	node12->right = node30;

	node15->left = node36;

	TreeNode* root = bTreeToDll(node10);

	while(root)
	{
		cout << root->val << "  ";
		root = root->right;
	}

	cout << endl;
}




