/******************************************************************************/
/*
* Question: #109 Convert Sorted List to Binary Search Tree
* Given a singly linked list where elements are sorted in ascending order, convert it to a heigh balanced BST.
*/
/*****************************************************************************/

#include <iostream>

#include "../Leetcode/BST.h"
#include "../Leetcode/ListNode.h"

// solution 1 - every time find the middle point and make it root
// then recursively build left tree and right tree.
// But this time complexity is O(nlogn)

// solution 2 - build the tree from bottom-up
// every time we need to make head point to the next and build the tree inorder
// time complexity is O(n)
TreeNode * buildTreeFromList(ListNode *& list, int start, int end)
{
	if (start > end) return NULL;
	int mid = start + (end - start) / 2;
	TreeNode * leftTree = buildTreeFromList(list, start, mid - 1);
	TreeNode * node = new TreeNode(list->val);
	node->left = leftTree;
	list = list->next;
	node->right = buildTreeFromList(list, mid + 1, end);
	return node;
}

TreeNode* sortedListToBST(ListNode * head) {
	int length = listLength(head);
	return buildTreeFromList(head, 0, length-1);
}

/*
int main(int argc, char ** argv)
{
	int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // size is 5
	int n = 10;
	ListNode * head = generateList(input, n);
	TreeNode * root = sortedListToBST(head);
	printPretty(root, 1, 0, cout);
	cout << "Hi this is LC 109" << endl;
}
*/
