﻿/******************************************************************************
* Question: #160 Intersection Of Two Linked Lists
* company tag: LinkedIn
* Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
					↘
					c1 → c2 → c3
					↗
B:     b1 → b2 → b3
begin to intersect at node c1.

* Notes:
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
*****************************************************************************/

#include "../Leetcode/ListNode.h"
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	ListNode * l1 = headA;
	ListNode * l2 = headB;

	// scan both array
	while (l1 != NULL && l2 != NULL)
	{
		if (l1 == l2) return l2;
		l1 = l1->next;
		l2 = l2->next;
	}

	// switch starting pointer
	if (l2 == NULL) l2 = headA;
	else l1 = headB;

	while (l1 != NULL && l2 != NULL)
	{
		l1 = l1->next;
		l2 = l2->next;
	}

	// after second round switch back
	if (l2 == NULL) l2 = headA;
	else l1 = headB;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1 == l2) return l2;
		l1 = l1->next;
		l2 = l2->next;
	}

	return NULL;
}
