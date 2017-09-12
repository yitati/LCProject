/******************************************************************************
* Question: #203 Remove Linked List Elements
* company tag: PureStorage
* Remove all elements from a linked list of integers that have value val.
* Example
* Given: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
* Return: 1 -> 2 -> 3 -> 4 -> 5
*****************************************************************************/

#include "ListNode.h"
#include <iostream>

using namespace std;


ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL) return head;
	ListNode * dummy = new ListNode(val - 1);
	dummy->next = head;
	ListNode * ptr = dummy;
	while (ptr->next)
	{
		if (ptr->next->val == val)
		{
			ListNode * tmp = ptr->next;
			ptr->next = tmp->next;
			delete tmp;
		}
		else
		{
			ptr = ptr->next;
		}
	}

	head = dummy->next;
	delete dummy;
	return head;
}


