/******************************************************************************/
/**
* Question: #141 Linked List Cycle
* Given a linked list, determine if it has a cycle in it.

* Follow up:
* Can you solve it without using extra space?
*/
/*****************************************************************************/

#include "../Leetcode/ListNode.h"

using namespace std;

bool hasCycle(ListNode *head) 
{
	ListNode * fast = head;
	ListNode * slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}
