/******************************************************************************/
/*
* Question: #21 Merge Two Sorted Lists
* Merge two sorted linked lists and return it as a new list. 
* The new list should be made by splicing together the nodes of the first two lists.
*/
/*****************************************************************************/

#include "ListNode.h"
#include <climits>

ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	ListNode* tail = NULL;

	while (l1 != NULL || l2 != NULL)
	{
		int opt1 = l1 == NULL ? INT_MAX : l1->val;
		int opt2 = l2 == NULL ? INT_MAX : l2->val;
		ListNode * newNode = new ListNode(0);
		if (opt1 <= opt2)
		{
			newNode->val = opt1;
			l1 = l1 == NULL ? NULL : l1->next;
		}
		else
		{
			newNode->val = opt2;
			l2 = l2 == NULL ? NULL : l2->next;
		}

		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	ListNode* head = NULL;
	ListNode * tail = head;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			if (head == NULL)
			{
				head = l1;
			}
			else
			{
				tail->next = l1;
			}
			tail = l1;
			l1 = l1->next;
		}
		else
		{
			if (head == NULL)
			{
				head = l2;
			}
			else
			{
				tail->next = l2;
			}
			tail = l2;
			l2 = l2->next;
		}
		tail->next = NULL;
	}
	if (l1 == NULL) tail->next = l2;
	else if (l2 == NULL) tail->next = l1;
	return head;
}
