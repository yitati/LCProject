/*
 * Basic: How to find the middle node of a linked list?
 */

#include "ListNode.h"

using namespace std;


/*
 *  if we find middle node using below function, then
 *  - for odd node numbers, we will return the middle one
 *  - for even node numbers, we will return the lhs middle node
 *    so that if we need to access the rhs, we can simly do -> next
 */
ListNode* findMiddleNode(ListNode* head)
{
	if(!head) return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}




