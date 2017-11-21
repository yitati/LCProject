/*
 * CycleNodeInLinkedList.cpp
 *

Check if a given linked list has a cycle. Return the node where the cycle starts. Return null if there is no cycle.

 */


#include "../Leetcode/ListNode.h"

ListNode* getCycleNode(ListNode* head)
{
	if(!head || !head->next) return NULL;
	bool hasCycle = false;
	ListNode* slow = head;
	ListNode* fast = head;

	// base case slow == fast
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
		{
			hasCycle = true;
			break;
		}
	}

	if(!hasCycle) return NULL;
	fast = head;

	while(fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}
