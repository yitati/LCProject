/*
 * Laicode_SelectionSortLinkedList.cpp
 *
Given a singly-linked list, where each node contains an integer value, sort it in ascending order.
The selectoin sort algorithm should be used to solve this problem.

Examples

null, is sorted to null
1 -> null, is sorted to 1 -> null
1 -> 2 -> 3 -> null, is sorted to 1 -> 2 -> 3 -> null
4 -> 2 -> 6 -> -3 -> 5 -> null, is sorted to 2 -> 3 -> 4 -> 5 -> 6
 */


#include "../LCProject/ListNode.h"

// find the min node and put it to the head of the list
ListNode* MoveMinNode(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* curr = head;

	ListNode* minPrev = prev;
	ListNode* minNode = curr;

	while(curr)
	{
		if(curr->val < minNode->val)
		{
			minPrev = prev;
			minNode = curr;
		}
		prev = curr;
		curr = curr->next;
	}

	if(minPrev)
	{
		minPrev->next = minNode->next;
		minNode->next = head;
	}

	return minNode;
}


ListNode* selectionSort(ListNode* a)
{
	ListNode* curr = a;
	ListNode* head = NULL;
	ListNode* tail = NULL;

	while(curr)
	{
		ListNode* sortOne = MoveMinNode(curr);
		curr = sortOne->next;
		// cut the sorted list
		sortOne->next = NULL;
		// connect with previous result
		if(!head)
		{
			head = sortOne;
			tail = sortOne;
		}
		else
		{
			tail->next = sortOne;
			tail = tail->next;
		}
	}

	return head;
}

