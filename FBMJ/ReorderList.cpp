/******************************************************************************
* Question: #143 Reorder List
* company tag: Facebook
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

* You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*****************************************************************************/

#include "ListNode.h"

void reorderList(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return;

	ListNode * slow = head;
	ListNode * fast = head->next;
	// to decide which half is shorter
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode * half = slow->next;
	slow->next = NULL;
	fast = reverseList(half);
	slow = head;
	while (fast)
	{
		ListNode * slowNext = slow->next;
		ListNode * fastNext = fast->next;
		slow->next = fast;
		fast->next = slowNext;
		slow = slowNext;
		fast = fastNext;
	}
}
