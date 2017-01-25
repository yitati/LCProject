/******************************************************************************/
/**
* Question: #206 Reverse Linked List
* Reverse a singly linked list.
*/
/*****************************************************************************/

#include "ListNode.h"
#include <iostream>

using namespace std;


ListNode* reverseList(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return head;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	while (head->next)
	{
		ListNode * curr = head->next;
		head->next = curr->next;
		curr->next = dummy->next;
		dummy->next = curr;
	}

	head = dummy->next;
	delete dummy;
	return head;
}

