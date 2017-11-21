/******************************************************************************/
/**
* Question: #237 Delete Node in a Linked List
* Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
* Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
* the linked list should become 1 -> 2 -> 4 after calling your function.
*/
/*****************************************************************************/

#include "../Leetcode/ListNode.h"

void deleteNode(ListNode* node) 
{
	ListNode * curr = node;
	while (curr)
	{
		// last node
		ListNode * currNext = curr->next;
		curr->val = currNext->val;
		if (currNext->next == NULL)
		{
			delete currNext;
			curr->next = NULL;
		}
		curr = curr->next;
	}
}