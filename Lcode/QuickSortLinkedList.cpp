/*
 * Laicode_QuickSortLinkedList.cpp
 *

Given a singly-linked list, where each node contains an integer value, sort it in ascending order.
The quick sort algorithm should be used to solve this problem.

Examples

null, is sorted to null
1 -> null, is sorted to 1 -> null
1 -> 2 -> 3 -> null, is sorted to 1 -> 2 -> 3 -> null
4 -> 2 -> 6 -> -3 -> 5 -> null, is sorted to -3 -> 2 -> 4 -> 5 -> 6

 */


#include "../Leetcode/ListNode.h"

/*
 * choose a pivot point and have two linked list
 *
 */
ListNode* quickSort(ListNode* a)
{
	// base case
	if(!a || !a->next) return a;

	ListNode* lhs = new ListNode(-1);
	ListNode* dummyl = lhs;
	ListNode* rhs = new ListNode(1);
	ListNode* dummyr = rhs;

	ListNode* curr = a->next;
	a->next = NULL;

	// partition the list into two linked list
	while(curr)
	{
		if(curr->val <= a->val)
		{
			lhs->next = curr;
			lhs = curr;
			curr = curr->next;
			lhs->next = NULL;
		}
		else {
			rhs->next = curr;
			rhs = curr;
			curr = curr->next;
			rhs->next = NULL;
		}
	}

	lhs = dummyl->next;
	rhs = dummyr->next;

	delete dummyl;
	delete dummyr;

	lhs = quickSort(lhs);
	rhs = quickSort(rhs);

	if(lhs)
	{
		curr = lhs;
		while(curr->next)
		{
			curr = curr->next;
		}
		curr->next = a;
	}
	else
	{
		lhs = a;
	}

	a->next = rhs;

	return lhs;
}

/*
int main(int argc, char ** argv)
{
	vector<int> input = {4, 2, 6, 3, 5};
	ListNode* a = generateList(input);
	a = quickSort(a);
	printList(a);
}

*/
