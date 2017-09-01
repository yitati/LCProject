/******************************************************************************
* Question: #206 Reverse Linked List
* company tag: Facebook, eBay
* Reverse a singly linked list.
*****************************************************************************/

#include "ListNode.h"
#include <iostream>

using namespace std;

/*
 * iteration solution
 */
ListNode* reverseList_iterative(ListNode* head)
{
	ListNode * prev = NULL;
	ListNode * next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

/*
 * recursion solution
 */
ListNode* reverseList_recursion(ListNode* head)
{
	if (!head || !head->next) return head;
	ListNode* newHead = reverseList_recursion(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

