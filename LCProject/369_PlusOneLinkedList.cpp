/******************************************************************************/
/**
* Question: #369 Plus One Linked List
* Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
* You may assume the integer do not contain any leading zero, except the number 0 itself.
* The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3
Output:
1->2->4

*/
/*****************************************************************************/

#include "ListNode.h"

using namespace std;

int addOne(ListNode* node);
ListNode* plusOne(ListNode* head)
{
	if (!head) return new ListNode(1); // if NULL return a new node
	if (addOne(head) != 0) // if we still have carry, create a new head and link to head
	{
		ListNode * newHead = new ListNode(1);
		newHead->next = head;
		head = newHead;
	}
	return head;
}
int addOne(ListNode* node)
{
	int carry = node->next ? addOne(node->next) : 1;  // if last node, add 1, otherwise add carry
	int sum = node->val + carry;
	node->val = sum % 10;
	return sum / 10;
}
