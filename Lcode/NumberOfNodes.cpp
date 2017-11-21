/*
 * Laicode_NumberOfNodes.cpp
 *

Return the number of nodes in the linked list.

Examples

L = null, return 0
L = 1 -> null, return 1
L = 1 -> 2 -> null, return 2

 */

#include "../Leetcode/ListNode.h"

int numberOfNodes(ListNode* head)
{
	int count = 0;
	while(head)
	{
		count++;
		head = head->next;
	}
	return count;
}




