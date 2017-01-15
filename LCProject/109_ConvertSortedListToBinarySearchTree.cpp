/******************************************************************************/
/*
* Question: #109 Convert Sorted List to Binary Search Tree
* Given a singly linked list where elements are sorted in ascending order, convert it to a heigh balanced BST.
*/
/*****************************************************************************/

#include "BST.h"
#include "ListNode.h"

// solution 1 - transfer list to array and build tree from array
// solution 2 - build the tree from bottom-up !! this is a very cleaver way !!


TreeNode * buildTreeFromList(ListNode *& list, int start, int end)
{
	if (start > end) return NULL;
	int mid = start + (end - start) / 2;
	TreeNode * leftTree = buildTreeFromList(list, start, mid - 1);
	TreeNode * node = new TreeNode(list->val);
	node->left = leftTree;
	list = list->next;
	node->right = buildTreeFromList(list, mid + 1, end);;
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


	system("pause");
}
*/