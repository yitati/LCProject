
#include "ListNode.h"

// need to know how to do this in 1 min !!!
// Time complexity O(n)
// Space complexity O(n) - depth of the call stack

// Solution 1 - iterative way
ListNode * reverseList_iterative(ListNode * head)
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

// Solution 2 - recursive way
ListNode * reverseList_recursive(ListNode * head)
{
	// base case
	if (!head || !head->next) return head;
	// handle all the rest nodes
	ListNode * newHead = reverseList(head->next);
	// connect with head
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

// We need to understand and know how to draw the recursion tree
// Figure out the subproblem