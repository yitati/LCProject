/******************************************************************************
* Question: #24 Swap Nodes In Pairs
* company tag: Facebook
* Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
* Your algorithm should use only constant space. You may not modify the values in the list,
* only nodes itself can be changed.
*****************************************************************************/

#include "ListNode.h"

/*
 * Solution 1 - recursion solution
 */
ListNode* swapPairs_recursion(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* second = head->next;
	second->next = swapPairs_recursion(second->next);
	head->next = second->next;
	second->next = head;
	return second;
}

/*
 * Solution 2 - iteration solution
 */
ListNode* swapPairs_iteration(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while(prev->next && prev->next->next)
    {
        ListNode* curr = prev->next;
        ListNode* cnext = curr->next;

        curr->next = cnext->next;
        cnext->next = prev->next;
        prev->next = cnext;

        prev = curr;
    }

    head = dummy->next;
    delete dummy;
    return head;
}
