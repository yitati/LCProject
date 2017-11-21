#include "../Leetcode/ListNode.h"
// N1 -> N2 -> N3 -> N4 -> N5 -> N6 -> NULL 
// It will stop at N3
ListNode * findMiddleNode(ListNode * head)
{
	if (head == NULL) return NULL;
	ListNode * slow = head, *fast = head;
	while (!fast->next && !fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}