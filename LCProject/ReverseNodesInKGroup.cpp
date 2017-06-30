/******************************************************************************/
/**
* Question: #25 Reverse Nodes In K-Group
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* k is a positive integer and is less than or equal to the length of the linked list. 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* You may not alter the values in the nodes, only nodes itself may be changed.
* Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
/*****************************************************************************/

#include "ListNode.h"

ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == NULL || head->next == NULL || k == 1) return head;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * prev = dummy, *curr = head;
	int len = 0;
	while (curr) { curr = curr->next; len++; }
	int loop = len / k;
	curr = head;
	while (loop && curr)
	{
		int inLoop = k - 1;
		while (inLoop)
		{
			ListNode * tmp = curr->next;
			curr->next = tmp->next;
			ListNode * prevNext = prev->next;
			prev->next = tmp;
			tmp->next = prevNext;
			inLoop--;
		}
		prev = curr;
		curr = curr->next;
		loop--;
	}

	head = dummy->next;
	delete dummy;
	return head;
}