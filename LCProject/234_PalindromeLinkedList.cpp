/******************************************************************************/
/**
* Question: #234 Palindrome Linked
* Given a singly linked list, determine if it is a palindrome.

* Follow up:
* Could you do it in O(n) time and O(1) space?
*/
/*****************************************************************************/

#include "ListNode.h"

bool isPalindrome(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return true;
	ListNode * fast = head;
	ListNode * slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = reverseList(slow);
	slow = head;
	while (fast)
	{
		if (slow->val != fast->val) return false;
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}