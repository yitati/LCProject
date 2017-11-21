/*
 * Laicode_MergeSortLinkedList.cpp
 *

Given a singly-linked list, where each node contains an integer value,
sort it in ascending order. The merge sort algorithm should be used to solve this problem.

Examples

null, is sorted to null
1 -> null, is sorted to 1 -> null
1 -> 2 -> 3 -> null, is sorted to 1 -> 2 -> 3 -> null
4 -> 2 -> 6 -> -3 -> 5 -> null, is sorted to -3 -> 2 -> 4 -> 5 -> 6

 */

#include "../Leetcode/ListNode.h"

ListNode* mergeSort(ListNode* a)
{
	if(!a || !a->next) return a;
	// split the list into halves
	ListNode* slow = a;
	ListNode* fast = a->next;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = NULL;
	slow = a;

	// mergesort both halves
	fast = mergeSort(fast);
	slow = mergeSort(slow);

	// merge sorted lists
	ListNode* dummy = new ListNode(0);
	ListNode* prev = dummy;
	while(fast || slow)
	{
		if(!fast)
		{
			prev->next = slow;
			break;
		}
		else if(!slow)
		{
			prev->next = fast;
			break;
		}
		else
		{
			if(fast->val <= slow->val)
			{
				prev->next = fast;
				prev = fast;
				fast = fast->next;
			}
			else
			{
				prev->next = slow;
				prev = slow;
				slow = slow->next;
			}
			prev->next = NULL;
		}
	}

	a = dummy->next;
	delete dummy;
	return a;
}

/*
int main(int argc, char ** argv)
{
	vector<int> input = {4, 2, 6, 3, 5};
	ListNode* a = generateList(input);
	a = mergeSort(a);
	printList(a);

}
*/




