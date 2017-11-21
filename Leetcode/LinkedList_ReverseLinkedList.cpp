
#include "../Leetcode/ListNode.h"

// need to know how to do this in 1 min !!!
// Time complexity O(n)
// Space complexity O(n) - depth of the call stack

// Solution 1 - iterative way
ListNode * reverseList(ListNode * head)
{
	if (!head) return NULL;
	ListNode * prevNode = NULL;
	ListNode * nextNode = NULL;
	while (head)
	{
		nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}
	return prevNode;
}

