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

